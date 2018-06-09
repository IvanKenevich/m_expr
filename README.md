# m_expr

## Basic Overview

The idea behind the expression evaluator is to build a hierarchical model of the expression from a string of
symbols. The model chosen is a Binary Tree. 

Expressions first get parsed sequentially into three types of entities:
1. Numbers
2. Operators
3. Groupings

These entities are sequentially added to one of the (possibly) many trees in existence.
The trees are managed by a common stack that helps create structure and hierarchy.

Once the string has ended (and the trees have been built), the model can be recursively evaluated with a simple
traversal of the Tree.

## More on Numbers

Numbers are created by recursively checking characters in a string left to right until the character isn't a digit.
This will generate the starting and ending indices for a sequence of digits which gets converted into a decimal number
This decimal number then gets wrapped into a VALUE Node and added to the working tree.

Grammar model for a Number:

```
<num> = {<digit> | <digit><num>}
<digit> = {0 | ... | 9}
```

In words:

A number is a digit or a digit followed by a number, where digit is 0 or 1 or ... or 9.

## More on Operators

Operators are recognized by checking if a character is one of the allowed operators.
This operator gets wrapped into the appropriate type of Node and added to the working tree.

Order of operations in arithmetic requires some caution when adding new operators. For example,
the expression 10 + 2 * 5 will get built from left to right and thus + will be recognized before. 
Therefore a program has to keep track of the previous operator that has been added.

This amounts to knowing the parent of the current working node and comparing its order with the order of the
operator to be inserted:

If a new operator has a lower (or equal) precedence than the most recent parent, make it a parent of that
parent. If it has a higher precedence, make it a child of that parent.

The reason that only the operator of the immediate parent of the current working node has to be known 
is based on the fact that the underlying Tree structure is Binary.

## More on Groupings

Groupings are themselves split into two types based on what they do:

1. Beginning of a group
2. Ending of a group

Beginning of a group groupings are "BEGINNING OF A STRING" and "("
Ending of a group groupings are "ENDING OF A STRING" and ")"

From the requirement that beginning and ending of the input string are recognized as groupings follows the existence
of the so-called 0th tree.
0th tree (T0) is the "root tree" of the expression. It can be the only tree if the expression is simple but in
a more general case it contains ALL other trees (that is, it itself is not contained within a tree).
T0 is the tree that gets finished last and it is the tree where recursive evaluation starts when the expression
has been fully built into a tree.

The groupings are used to manipulate the stack of Trees and stack of pointers to Tree root pointers 
which are discussed in more detail in their respective sections.

## More on Stacks

Stack of Trees:

In order to deal with groupings, a stack of trees is introduced.
Whenever a beginning of a group is encountered, a new tree is created and the reference to it is pushed onto a stack.
Any symbols always get added to the tree on the top of the stack.
Whenever an ending of a group is encountered, a tree reference is popped off of the stack.
Before any parsing, the stack is empty, as soon as the beginning of the string is encountered, the 0th tree
gets created and a reference to it gets pushed onto the stack.

Stack of pointers to Tree roots:

```
struct eh {
    Node ** to_be_updated;
    Node ** to_update_from;
}
```

To be copied from the wall.

Just realized... can (must) the two be combined into one?

## Some examples of the models that will get built:

```
(5+2)/(5-3)
becomes
<div>(
    <add>(
        <val>(5),
        <val>(2)
    ),
    <sub>(
        <val>(5),
        <val>(3)
    )
)
```

```
(1+2)-(3+4)
becomes
<sub>(
    <add>(
        <val>(1),
        <val>(2)
    ),
    <add>(
        <val>(3),
        <val>(4)
    )
)
```

symbols:

* "start" - beginning of the string (abstract, not an actual character)
* "end" - ending of the string (abstract, could be '\0' in C/C++)
* "number" - a digit
* "operator" - any arithmetic operator
* "(" - begin group
* ")" - end group

Math grammar:

* "start" is followed by "number" or "("
* "end" is followed by nothing
* "number" is followed by "number" or "operator" or ")" or "end"
* "(" is followed by "number" or "("
* ")" is followed by "operator" or ")" or "end"
* every "(" must be eventually followed by ")"

```
((5+2)-(3+2))

What if you first run a group parser that splits into generic expressions that get assigned a `level of depth`?
"start" - begin group 0
"(" - begin group 10
"(" - begin group 20
"skip everything that isn't a group"
")" - end group 20
"skip everything that isn't a group"
"(" - begin group 21
"skip everything that isn't a group"
")" - end group 21
")" - end group 10
"end" - end group 0

you encounter "0(", you start building e0<generic>, any expression that follows will be the first
operand of e0
you encounter "1(", you start building e1<generic>

```

```
Every possible expression type should have a "Builder"

if "(" is encountered, start building a generic expression
if ")" is encountered, end building a generic expression
if "operator" is encountered, make current expression an "operator" expression
if "number" is encountered, build a <val> expression
    "number" must be followed by an operator or ")" or "end"
```
