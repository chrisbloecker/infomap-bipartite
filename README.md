# Infomap Software Package

Infomap is a network clustering algorithm based on the
[Map equation](http://www.mapequation.org/publications.html#Rosvall-Axelsson-Bergstrom-2009-Map-equation).

In this branch, we implement the bipartite map equation with varying node-type memory based on
[the bipartite map equation]().
In the future, we will merge this work into the [main infomap repository](https://github.com/mapequation/infomap).

For more info, see [www.mapequation.org](http://www.mapequation.org).


Compiling:
--------------------------------------------------------
In a terminal with the GNU Compiler Collection installed,
just run `make` in the current directory to compile the
code with the included `Makefile`. Call `./Infomap` to run.

Run `./Infomap --help` or visit [options](http://www.mapequation.org/code.html#Options)
for a list of available options.

Infomap can be used both as a standalone program and as a library.
See the `examples` folder for examples.

We also include an [IPython notebook](examples/python/infomap-examples.ipynb)
with the examples that can be viewed online.


Quickstart:
--------------------------------------------------------
To run the bipartite version of Infomap, you need to encode your network in the following format

```
# comments...
*Vertices n
1 "node 1 name"
2 "node 2 name"
...
n "node n name"
*Bipartite m
a x 42
b y 3.14
...
```
where
- `n` is the number of nodes
- `m` is the ID of the first right node
- `a` is a left node with `a < m`
- `b` is a left node with `b < m`
- `x` is a right node with `x ≥ m`
- `y` is a right node with `y ≥ m`
- `42` and `3.14` are carefully chosen random weights for the two edges `(a,x)` and `(b,y)`

Assuming your network is stored in a file called `bipartite.net`, you can analyse it by running `InfomapBipartite bipartite.net out` where `out` is the folder where Infomap will place the result.


Authors:
--------------------------------------------------------
Christopher Blöcker,
Daniel Edler,
Martin Rosvall

For contact information, see
http://www.mapequation.org/about

For a list of recent feature updates, see
CHANGES.txt in the source directory.

Terms of use:
--------------------------------------------------------
The Infomap software is released under a dual licence.

To give everyone maximum freedom to make use of Infomap
and derivative works, we make the code open source under
the GNU Affero General Public License version 3 or any
later version (see LICENSE_AGPLv3.txt.)

For a non-copyleft license, please contact us.
