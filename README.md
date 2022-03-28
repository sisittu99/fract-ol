# 42-Tutorial: Fract-ol

# Il Subject

Questo progetto permette di:
* 🎨 imparare ad utilizzare la libreria MiniLibX, un insieme di funzioni grafiche molto semplici da utilizzare e, ahimè, per questo molto poco ottimizzate nella compilazione ed esecuzione dei vari progetti;
* 🧮 ripassare (prendo per certo che li abbiate già affrontati al liceo o all'università) l'insieme dei *numeri complessi* e il loro funzionamento, tastando con mano un loro effettivo utilizzo;
* 🌿 studiare il fantastico e meraviglioso mondo dei **frattali**, la cui definizione [secondo Wikipedia](https://it.wikipedia.org/wiki/Frattale) è 
> "un oggetto geometrico dotato di omotetia interna: **si ripete nella sua forma allo stesso modo su scale diverse**, e dunque ingrandendo una qualunque sua parte si ottiene una figura simile all'originale. 
> 
> [...]
> 
> Deriva dal latino **fractus** *(rotto, spezzato)*, così come il termine frazione; infatti le immagini frattali sono considerate dalla matematica *oggetti di dimensione anche non intera*."

Sarà particolarmente faticoso per me scrivere un tutorial prettamente teorico sui frattali, pertanto non posso innanzitutto non mandarvi a video esplicativi che vi permettano di capire di cosa si sta davvero parlando. Molto utile in tal senso il canale YT di One Brown Three Blue, che da anni aiuta studenti ed appassioanti a visualizzare in maniera semplice concetti matematici complessi.
Quindi, partite da qui! Ci rivedremo non appena avrete un'idea più chiara.
* [(Youtube) Beyond the Mandelbrot set, an intro to holomorphic dynamics](https://www.youtube.com/watch?v=LqbZpur38nw)
* [(Youtube) I frattali non sono in genere auto-similari.](https://www.youtube.com/watch?v=gB9n2gHsHN4)
* [Primitive e integrali indefiniti](https://www.youmath.it/lezioni/analisi-matematica/integrali/597-primitive-e-integrale-indefinito.html) (Da qui cercate di ripassare giusto i concetti da liceo. Non vi serviranno realmente nella stesura del codice, ma è un concetto importante e sulla base di questo implemento la possibilita (richiesta!) di passare da Mandelbrot a Julia, ossia la sua primitiva.)
* [L'insieme di Mandelbrot](https://it.wikipedia.org/wiki/Insieme_di_Mandelbrot)
* [L'insieme di Julia](https://it.wikipedia.org/wiki/Insieme_di_Julia)
* [Julia Set Generator](https://marksmath.org/visualization/julia_sets/) (probabilmente il link che mi ha aiutato di più!)
* [Il frattale Burning Ship](https://it.wikipedia.org/wiki/Burning_ship) (bonus)

# La teoria
## i numeri complessi
Per spiegare questo progetto, baseremo tutto su Mandelbrot e poi spiegheremo le differenze minime ma necessarie con gli altri due.
Deve esservi anzitutto chiara la definizione di numero immaginario, dove **i = &#8730;(-1)**. Vi ricorda qualcosa? Bene, perché ovviamente il concetto successivo è quello dell'**insieme dei numeri complessi**, che in questo progetto è imprescindibile.
Per coloro che hanno qualche dubbio, vi ricordo che i numeri complessi appartengono all'insieme immaginario, dove 

&forall; a, b &isin; &#8477;, 

z = (a + ib) &isin; &#8450;

Spero davvero che solo leggere queste due righe vi abbia già riacceso una lampadina, altrimenti devo invitarvi a un ripasso generale. Questa [breve intro](https://www.youmath.it/lezioni/analisi-matematica/numeri-complessi/2697-definizione-di-numero-complesso.html) all'argomento sarà sufficiente al momento.
Il mio compito qui invece sarà cercare di aiutarvi nella lettura e nel ragionamento della richiesta di questo progetto.

Per quanto i numeri complessi nella teoria sono pensati come un numero singolo (il nostro z), la loro rappresentazione avviene in un piano cartesiano dove
1) l'ascisse è composta dalla parte reale del numero, equivalente al numero appartenente a &#8477;
2) la coordinata è invece composta dalla parte immaginaria, ossia tutti i numeri ai quali è possibile raccogliere la i.

Esempio:

![image](https://user-images.githubusercontent.com/92301111/160387576-9dd22391-a095-41c3-b73a-7ebea781ae3f.png)
> crediti a YouMath


Siccome il nostro computer, specie nel linguaggio C, non abbiamo una gestione diretta dei numeri complessi... L'idea condivisa da molti è quella di partire da una struct per ogni numero complesso così definita:
```
typedef struct s_cpx
{
	double	x;
	double	y;
}	t_cpx;
```
Da qui poi si gestiranno tutte le operazioni matematiche attraverso funzioni dedicate, rispettando ovviamente tutte le regole del caso. Vi lascio l'esempio dell'addizione, tutto il resto sarà in mano vostra. Lasciatevi aiutare da [questo formulario](https://www.youmath.it/lezioni/analisi-matematica/numeri-complessi/773-operazioni-con-i-numeri-complessi.html)!

```
t_cpx	ft_add_cpx(t_cpx a, t_cpx b)
{
	t_cpx	added;

	added.x = a.x + b.x;
	added.y = a.y + b.y;
	return (added);
}
```
## le successioni numeriche

Tutta la teoria di questo progetto è basato sulle successioni. Le spiegherò velocemente, ma non sarà così poco intuitivo... spero😅

Le successioni sono funzioni definite su &#8469; *(interi positivi)* con valori solitamente su &#8477;, ma nulla ci vieta di utilizzare anche l'insieme &#8450;!

La successione più famosa è sicuramente quella di Fibonacci, che vien così definita:

&forall; n  &isin; &#8469;

F<sub>0</sub> = 0

F<sub>1</sub> = 1

F<sub>n+1</sub> = F<sub>n</sub> + F<sub>n-1</sub>

dove i primi numeri saranno così definiti: 
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233... Chiaro, no?


Per l'insieme di Mandelbrot, abbiamo una situazione simile attraverso una formula banale all'occhio:

&forall; n &isin; &#8469;, c &isin; &#8477;

z<sub>n+1</sub> = z<sub>n</sub><sup>2</sup> + c
