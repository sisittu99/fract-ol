# 42-Tutorial: Fract-ol

<a href="https://github.com/JaeSeoKim/badge42"><img src="https://badge42.vercel.app/api/v2/cl2rgldpg003009ml52tile1w/project/2544218" alt="mcerchi's 42 fract-ol Score" /></a>

# The Subject

This project allows you to:
* 🎨 learn how to use the MiniLibX library, a set of graphical functions very simple to use and unfortunately very little optimized in the compilation and execution;
* 🧮 review (I assume you've already dealt with them during high school or college) the set of *complex numbers* and their functioning, feeling firsthand their effective use;
* 🌿 study the wonderfully fantastic world of **fractals**, whose definition [according to Wikipedia Italy](https://it.wikipedia.org/wiki/Frattale) (english version [here](https://en.wikipedia.org/wiki/Fractal)) is
> "a geometric object endowed with internal homothety: **repeats itself in its form in the same way on different scales**, and therefore by zooming any of its parts, a figure similar to the original is obtained.
> 
> [...]
> 
> It comes from the Latin **fractus** *(broken)*, as well as the term fraction; in fact, fractal images are considered by mathematics to be *objects of non-integer dimension*."

It will be particularly tiring for me to write a purely theoretical tutorial on fractals, so I can't help but send you explanatory videos that allow you to understand what we are really talking about. The One Brown Three Blue YT channel is very useful in this regard: for years it has helped students and amateurs to visualize complex mathematical concepts in a simple way.
So, go from here! We'll meet again as soon as you get a clearer idea.
* [(Youtube) Beyond the Mandelbrot set, an intro to holomorphic dynamics](https://www.youtube.com/watch?v=LqbZpur38nw)
* [(Youtube) Fractals are typically not self-similar.](https://www.youtube.com/watch?v=gB9n2gHsHN4)
* [(Youtube) Indefinite Integrals, Primitives, and Antiderivatives](https://www.youtube.com/watch?v=4vulVx9nuKw) (From here try to just review the concepts from high school. You won't really need them in writing the code, but it is an important concept and you'll have to implement the possibility to switch from Mandelbrot to Julia, which is its primitive of course.)
* [Mandelbrot set](https://en.wikipedia.org/wiki/Mandelbrot_set)
* [Julia set](https://en.wikipedia.org/wiki/Julia_set)
* [Julia Set Generator](https://marksmath.org/visualization/julia_sets/) (The most useful link I'll give ya fellows!)
* [Burning Ship fractal](https://en.wikipedia.org/wiki/Burning_Ship_fractal) (bonus part)
> please note: I'll avoid explaining MiniLibX in this tutorial: there are already too many mathematical arguments to allow me to write here also how to print a pixel with the given functions. By the way, there are some nice explanations and code examples [in this document](https://harm-smits.github.io/42docs/libs/minilibx)! Personally I also relied on [this link](https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx), which says more or less the same things and allows you to print pixels in the most suitable way possible.
>
> Just practice before starting! It will be very helpful for you to print a circle and to know how to move it around the screen, from then on your skills will be sufficient for this project.

# The theory
## complex numbers 🤔
In order to explain this project, we will base everything on Mandelbrot and then explain the differences within the others.
First of all, the definition of an imaginary number must be clear, where **i = &#8730;(- 1)**. Does it remind you of anything? Good then, 'cause obviously the next concept is the **set of complex numbers**, which is essential in this project.
For those who have any doubts, I remind you that complex numbers belong to the imaginary set, where

&forall; a, b &isin; &#8477;, 

z = (a + ib) &isin; &#8450;

> I really hope that just reading these two lines has given you a brainwave, otherwise I have to invite you to a general review. This [short intro](https://www.mathsisfun.com/numbers/complex-numbers.html) will suffice at the moment.
> My task here will be only to try to help you in reading and reasoning the request for this project.

Although complex numbers in theoretically are thought of as a single number (our z), their representation occurs in a Cartesian plane where
1) the abscissa is composed of the real part of the number, equivalent to the number belonging to &#8477;
2) the coordinate is instead composed of the imaginary part, that is all the numbers at which it is possible to collect the i as a factor.

Ex:

![image](https://user-images.githubusercontent.com/92301111/160387576-9dd22391-a095-41c3-b73a-7ebea781ae3f.png)

Since in our computer, especially using C, we do not have a direct management of complex numbers, the idea shared by most people is to start from a struct for each complex number defined as follows:
```
typedef struct s_cpx
{
	double	x;
	double	y;
}	        t_cpx;
```
From here any math operation will be managed through dedicated functions, obviously respecting all the relevant rules. I leave you the example of addition, everything else will be in your hands.

```
t_cpx	ft_add_cpx(t_cpx a, t_cpx b)
{
	t_cpx	added;

	added.x = a.x + b.x;
	added.y = a.y + b.y;
	return (added);
}
```
I'll leave you the formulas here!

![3417cd5986b284894846da77f6436043](https://user-images.githubusercontent.com/92301111/163218675-3813fb75-28b9-4e01-b025-82863d3ace6a.jpeg)

## the numerical sequences 🔢

The whole theory of this project is based on sequences. I'll explain quickly, but it won't be so unintuitive... at least, I hope so😅

Sequences are functions defined on &#8469; (set of positive integers) with values usually on &#8477;, but nothing prevents us from using also the set &#8450;!

### example: the Fibonacci sequence

The most famous sequence is certainly the Fibonacci one, which is defined as follows:

&forall; n  &isin; &#8469;

⎧ F<sub>0</sub> = 0

⎨ F<sub>1</sub> = 1

⎩ F<sub>n+1</sub> = F<sub>n</sub> + F<sub>n-1</sub>

where the first numbers result in `0 - 1 - 1 - 2 - 3 - 5 - 8 - 13 - 21 - 34 - 55 - 89 - 144 - 233 - ... `. Simple as that!

### The Mandelbrot Sequence 🍑
We have a similar situation through a seemingly trivial formula:

&forall; n &isin; &#8469;, c &isin; &#8450;

z<sub>n+1</sub> = (z<sub>n</sub>&sup2; + c) &isin; &#8450;

> Actually, this sequence can be defined with an exponent x &isin; &#8477;, where to the tendency of x &rarr; +&infin; we will have a circle. Google *Multibrot* to learn more!

The basic idea is this: the belonging of a point to the Mandelbrot set allows to find infinite points belonging to the same set using the above sequence.
To do this, we assign the value of our point p = (a + ib) to the constant c of the sequence. We will therefore have:

* z<sub>0</sub> = 0 + p

* z<sub>1</sub> = z<sub>0</sub>&sup2; + c = p&sup2; + p 

* z<sub>2</sub> = z<sub>1</sub>&sup2; + c = (p&sup2; + p)&sup2; + p 

* z<sub>3</sub> = z<sub>2</sub>&sup2; + c = [(p&sup2; + p)&sup2; + p]&sup2; + p

and so on!

If the number does not belong to the Mandelbrot set, the sequence will have values far from those that interest us and with a high probability it will diverge. Otherwise, tending n &rarr; +&infin; we will be able to find out all the points, and the result will be this:

<img width="627" alt="Screen Shot 2022-03-28 at 3 26 23 PM" src="https://user-images.githubusercontent.com/92301111/160407881-4ef8d1c4-14d3-4ec2-820f-5d9a4379d9a8.png">

We immediately read the image, so as to understand what our goal is. All the dark gray pixels clustered in this strange shape are the graphical representation of the points belonging to the Mandelbrot set. 

And what about the others? Well, those do not belong to the set of course; however, depending on their proximity to the whole, they will have values in the succession that are more or less close to those of the Mandelbrot ones, and therefore we'll assign them a specific colour that creates an optical effect pleasing to the eye. 

We will return to this topic in the "technical" section of this tutorial. Meanwhile, enjoy an example of a zoomed part:

<img width="635" alt="Screen Shot 2022-03-28 at 3 41 55 PM" src="https://user-images.githubusercontent.com/92301111/160410750-065bcc60-fd13-441a-83ed-7d546079f07c.png">

> Lovely, isn't it?
***

### Julia's function 🌿

If the Mandelbrot set is a succession of numbers, the Julia set is rather a *holomorphic function*. Perhaps you will be surprised to read that in Julia,

&fnof;<sub>c</sub>(z) = z&sup2; + c

Practically the calculation of the values respects the same rule, except that in this case the constant **is not the starting point!** Indeed, it is fixed for any point. That is because Julia is the *primitive function* of the Mandelbrot set, thus every constant has a set of points unlike any other. For example, this has the constant c = (0.285 + 0.01i)

<img width="378" alt="Screen Shot 2022-03-28 at 4 13 25 PM" src="https://user-images.githubusercontent.com/92301111/160417503-4079dd5e-fc7e-49ee-8915-02a7e02372ac.png">

this one has c = (-0.55 - 0.4894i)

<img width="630" alt="Screen Shot 2022-03-28 at 4 17 16 PM" src="https://user-images.githubusercontent.com/92301111/160418241-9db63ade-8457-4937-9bb9-20aef43f923d.png">

and this... c = (0 + 0i) (lol)

<img width="502" alt="Screen Shot 2022-03-28 at 4 19 49 PM" src="https://user-images.githubusercontent.com/92301111/160418724-d49bd33a-7fa8-449b-b617-5fe8ebf311e8.png">

***

### The Burning Ship Succession 🛳

It works exactly like Mandelbrot, but in addition it'll need to put everything in absolute value, making the formula become like this:

z<sub>n+1</sub> = |(z<sub>n</sub>&sup2; + c)| &isin; &#8450;

# The pseudo-code

If in maths we can generalize everything tending to infinity with no problem at all, in computer science we must set parameters and limits which'll be functional to what we want to see.
Why this? Because in the calculation of each point we will have to iterate the sequence or the function for x times, just to understand if the point is part of the set or not. It's quite obvious to say that CPU won't calculate infinite numbers for any pixel of the image...

The basic idea is that, if we are faced with a point slightly external to the whole, this will leave an area of our interest in i (< x) times, which we will limit in order not to tire the machine too much during rendering. Consider that already 10-20 iterations are enough to find the desired result! Then if you want to have a more reliable result just increase the value of x: the example photos above have 200 iterations for each point, just to allow you to better see the result.

How important is the value of x?

Not really much for the purpose of the result itself. The problem you will encounter will be the speed in rendering in very concentrated areas, as all the points belonging to the chosen set will iterate up to x, while the closest ones will arrive at x - 1, the next area after x - 2 and so on...

The pseudocode will come like this:
```
for(i = 0; i <= WIDTH; i++)
	for (j = 0; j <= HEIGHT; j++)
	{
		res = math_point(i, j);
		for(iterations = 0; iterations < x; iterations++)
		{
			res = calculate_function(res);
			if (res > borders)
				break;
		}
		calculate_colour(iterations);
	}
```
The first two cycles allow you to take each pixel into consideration.

The function itself will have function O large O(n&sup2;) for n &rarr; &infin;; however, as x increases, it will tend towards an overall O(n&sup3;) which makes the computation and rendering times much longer. It's up to you whether to choose a sufficient value both to show a decent image and not to waste too much time for those who want to zoom.

Please take care in choosing the right "borders"! Personally I reasoned using a circle that enclosed all the points I needed, but there are both more optimized methods or easiest ones (e.a. reasoning in rectangles).

# From pixels to the Cartesian plane

Wondering what `math_point(i, j)` is for in pseudo-code?
It simply converts the position of the pixel into the position of the Cartesian plane. It is a trivial proportion, where we will need:
* window width and length, `WIDTH` and` HEIGHT`
* the extremes of the Cartesian plane being printed, `max_x` `min_x` `max_y` and `min_y`
* the point on the screen being calculated.

Taking `i` and `j`, we will give `p = {x, y}` these values:
```
	    max_x - min_x
p.x = i * ----------------- + min_x
		WIDTH

	    max_y - min_y
p.y = j * ----------------- + min_y
		HEIGHT
```
Let's explain it quickly: 

`i` and `j` have pixels as the unit of measurement, so you have to divide them by the length (or width) of the dimension to find the right proportion. Therefore, we multiply it by the length of the Cartesian plane, in such a way as to have it proportioned correctly. Finally, since in 99% of cases the area will not be displayed from the origin, we will need to add everything together with the beginning of the displayed area.

The reason why we don't make the values explicit is, they will vary! Especially when you want to move or you want (you will have to!) to zoom to infinity. The only thing that will remain set will be the size of the window, at least at the beginning of compilation. Otherwise, whenever you need to change parameters, whether for a zoom or for a color change or for a passage to a new fractal, you will have to delete the image and recalculate it from scratch. While it's not the best thing to do, it's the only chance we have in this project. So take care to write your code well and make it work in any case!
***

We have reached a good point of the explanation. I did not go to explain everything to you because there are variations that you can take and I don't want to limit your creativity and your inventiveness in a project that is, after all, limiting compared to others. Know that in order to have fun you can find new functions to apply to your keys, you can create particular colors, calculate as many sets of fractals as possible ... and once delivered, you could even try to print the image in multi-thread or physically move the pixels already assigned without going to recalculate them every time, considerably speeding up the rendering!
> In this regard, I give a package of Haribo to whoever sends me the code for the dragon fractal 🐉

For any question, explanation, clarification, proposal or discussion you can always find me on Slack (@mcerchi) or [by mail](mailto: mcerchi@student.42roma.it). Have a good job!
