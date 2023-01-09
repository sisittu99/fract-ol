# 42-Tutorial: Fract-ol

<a href="https://github.com/JaeSeoKim/badge42"><img src="https://badge42.vercel.app/api/v2/cl2rgldpg003009ml52tile1w/project/2544218" alt="mcerchi's 42 fract-ol Score" /></a>

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

> N.b.: eviterò di spiegarvi MiniLibX in questo tutorial: gli argomenti matematici sono già troppi per poter scrivere qui come stampare un pixel con le funzioni date. Tuttavia, ci sono spiegazioni ed esempi di codice molto esplicativi [in questo documento](https://harm-smits.github.io/42docs/libs/minilibx)! Personalmente mi sono basato anche [su questo link](https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx), che dice più o meno le stesse cose e ti permette di stampare pixel nella maniera più consona possibile.
> 
>  Esercitatevi! Vi sarà molto d'aiuto arrivare a stampare un cerchio e saperlo muovere nello schermo, da lì in poi le competenze necessarie saranno sufficienti per questo progetto.

# La teoria
## i numeri complessi 🤔
Per spiegare questo progetto, baseremo tutto su Mandelbrot e poi spiegheremo le differenze minime ma necessarie con gli altri due.
Deve esservi anzitutto chiara la definizione di numero immaginario, dove **i = &#8730;(-1)**. Vi ricorda qualcosa? Bene, perché ovviamente il concetto successivo è quello dell'**insieme dei numeri complessi**, che in questo progetto è imprescindibile.
Per coloro che hanno qualche dubbio, vi ricordo che i numeri complessi appartengono all'insieme immaginario, dove 

&forall; a, b &isin; &#8477;, 

z = (a + ib) &isin; &#8450;

> Spero davvero che solo leggere queste due righe vi abbia già riacceso una lampadina, altrimenti devo invitarvi a un ripasso generale. Questa [breve intro](https://www.youmath.it/lezioni/analisi-matematica/numeri-complessi/2697-definizione-di-numero-complesso.html) all'argomento sarà sufficiente al momento.
> Il mio compito qui invece sarà cercare di aiutarvi nella lettura e nel ragionamento della richiesta di questo progetto.

Per quanto i numeri complessi nella teoria sono pensati come un numero singolo (il nostro z), la loro rappresentazione avviene in un piano cartesiano dove
1) l'ascisse è composta dalla parte reale del numero, equivalente al numero appartenente a &#8477;
2) la coordinata è invece composta dalla parte immaginaria, ossia tutti i numeri ai quali è possibile raccogliere la i.

Esempio:

![image](https://user-images.githubusercontent.com/92301111/160387576-9dd22391-a095-41c3-b73a-7ebea781ae3f.png)
> crediti a YouMath


Siccome nel nostro computer, specie nel linguaggio C, non abbiamo una gestione diretta dei numeri complessi... L'idea condivisa da molti è quella di partire da una struct per ogni numero complesso così definita:
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
## le successioni numeriche 🔢

Tutta la teoria di questo progetto è basato sulle successioni. Le spiegherò velocemente, ma non sarà così poco intuitivo... spero😅

Le successioni sono funzioni definite su &#8469; (insieme degli interi positivi) con valori solitamente su &#8477;, ma nulla ci vieta di utilizzare anche l'insieme &#8450;!

### esempio: la successione di Fibonacci

La successione più famosa è sicuramente quella di Fibonacci, che vien così definita:

&forall; n  &isin; &#8469;

⎧ F<sub>0</sub> = 0

⎨ F<sub>1</sub> = 1

⎩ F<sub>n+1</sub> = F<sub>n</sub> + F<sub>n-1</sub>

dove i primi numeri saranno quindi: 
`0 - 1 - 1 - 2 - 3 - 5 - 8 - 13 - 21 - 34 - 55 - 89 - 144 - 233 - ... `

Chiaro, no?

### La successione di Mandelbrot 🍑
Abbiamo una situazione simile attraverso una formula banale all'occhio:

&forall; n &isin; &#8469;, c &isin; &#8450;

z<sub>n+1</sub> = (z<sub>n</sub>&sup2; + c) &isin; &#8450;
> In realtà, questa successione è definibile con un esponente x &isin; &#8477;, dove al tendere di x &rarr; +&infin; avremo un cerchio. Cercate su Google *Multibrot* per saperne di più!

L'idea di fondo è questa: l'appartenenza di un punto all'insieme di Mandelbrot permette di trovare infiniti punti appartenenti allo stesso insieme utilizzando la successione di cui sopra. 
Per fare ciò, assegniamo il valore del nostro punto p = (a + ib) alla costante c della successione. Avremo quindi:

* z<sub>0</sub> = 0 + p

* z<sub>1</sub> = z<sub>0</sub>&sup2; + c = p&sup2; + p 

* z<sub>2</sub> = z<sub>1</sub>&sup2; + c = (p&sup2; + p)&sup2; + p 

* z<sub>3</sub> = z<sub>2</sub>&sup2; + c = [(p&sup2; + p)&sup2; + p]&sup2; + p


e così via!

Qualora il numero non dovesse appartenere all'insieme di Mandelbrot, la successione avrà valori ben lontani da quelli che ci interessano e con un'alta probabilità divergerà. In caso contrario, tendendo n &rarr; +&infin; riusciremo a scoprire tutti i punti, e il risultato sarà questo:

<img width="627" alt="Screen Shot 2022-03-28 at 3 26 23 PM" src="https://user-images.githubusercontent.com/92301111/160407881-4ef8d1c4-14d3-4ec2-820f-5d9a4379d9a8.png">

Leggiamo fin da subito l'immagine, così da capire qual è il nostro obiettivo. Tutti i pixel grigio scuro ammassati in questa strana forma sono la rappresentazione grafica dei punti appartenenti all'insieme di Mandelbrot. E gli altri?

Beh, quelli non vi appartengono, ma a seconda della loro vicinanza all'insieme avranno dei valori nella successione più o meno vicini a quelli dei punti di Mandelbrot, e verrà pertanto assegnato a loro un colore specifico che crea un effetto ottico piacevole all'occhio. Torneremo su questo tema nella sezione "tecnica" di questo tutorial. Intanto, godetevi un esempio di una parte zoomata:

<img width="635" alt="Screen Shot 2022-03-28 at 3 41 55 PM" src="https://user-images.githubusercontent.com/92301111/160410750-065bcc60-fd13-441a-83ed-7d546079f07c.png">

> Non è adorabile? 😍😍😍😍😍
***
### La funzione di Julia 🌿

Se l'insieme di Mandelbrot è una successione di numeri, quello di Julia è piuttosto una *funzione olomorfa*. Forse vi stupirà leggere che in Julia, 

&fnof;<sub>c</sub>(z) = z&sup2; + c

Praticamente il calcolo dei valori rispetta la stessa regola, se non fosse che in questo caso la costante **non è il punto di partenza!** Bensì è fissa per qualunque punto. Questo perché Julia è la *funzione primitiva* dell'insieme di Mandelbrot, e pertanto ogni costante ha un insieme di punti diverso da qualunque altra. Per esempio, questo ha come costante c = (0.285 + 0.01i)

<img width="378" alt="Screen Shot 2022-03-28 at 4 13 25 PM" src="https://user-images.githubusercontent.com/92301111/160417503-4079dd5e-fc7e-49ee-8915-02a7e02372ac.png">

mentre questo ha c = (-0.55 - 0.4894i)

<img width="630" alt="Screen Shot 2022-03-28 at 4 17 16 PM" src="https://user-images.githubusercontent.com/92301111/160418241-9db63ade-8457-4937-9bb9-20aef43f923d.png">

e qui c = (0 + 0i) (lol)

<img width="502" alt="Screen Shot 2022-03-28 at 4 19 49 PM" src="https://user-images.githubusercontent.com/92301111/160418724-d49bd33a-7fa8-449b-b617-5fe8ebf311e8.png">

***

### La successione della Burning Ship 🛳

Funziona esattamente come Mandelbrot, ma in più bisognerà mettere in valore assoluto ogni valore, facendo diventare la formula così:

z<sub>n+1</sub> = |(z<sub>n</sub>&sup2; + c)| &isin; &#8450;

# Lo pseudo-codice

Se in matematica possiamo generalizzare tutto tendendo all'infinito senza problemi, in informatica dobbiamo porre parametri e limiti funzionali a ciò che vogliamo fare.
Perché questo? Perché nel calcolo di ogni punto dovremo iterare la successione o la funzione per x volte, soltanto per capire se il punto fa parte dell'insieme o meno. 

L'idea di fondo è che, qualora ci trovassimo di fronte ad un punto lievemente esterno all'insieme, questo in i (< x) volte uscirà da un'area di nostro interesse, che andremo a limitare per non affaticare troppo la macchina durante la renderizzazione. Considerate che già 10-20 iterazioni sono sufficienti per trovare il risultato voluto! Poi se volete avere un risultato più affidabile basta aumentare il valore di x: le foto esempio sopra hanno 200 iterazioni per ogni punto, proprio per permettervi di vedere al meglio il risultato.

Quanto è importante il valore di x?

In realtà non molto ai fini del risultato in sé. Il problema che riscontrerete sarà più che altro la velocità nella renderizzazione in zone molto concentrate, in quanto tutti i punti appartenenti all'insieme scelto itereranno fino ad x, mentre quelli più vicini arriveranno a x - 1, la zona successiva ad x - 2 e cosi via...

Capite bene che lo pseudocodice verrà così:
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
I primi due cicli permettono di prendere ogni pixel in considerazione
La funzione di per sé avrà funzione O grande O(n&sup2;) per n &rarr; &infin;; tuttavia, all'aumentare di x, si tenderà piuttosto ad un complessivo O(n&sup3;) che rende molto più lunghi i tempi di calcolo e quindi quelli di renderizzazione. Sarà nel vostro interesse scegliere un valore sufficiente sia per mostrare un'immagine decente, sia per non far perdere troppo tempo a chi vuole zoomare.
> Funzione di O grande... [Sapete di cosa si sta parlando?](https://www.youmath.it/lezioni/analisi-matematica/limiti-continuita-e-asintoti/3260-o-grande-e-proprieta-degli-o-grande.html) Probabilmente lo avete già incontrato studiando gli algoritmi di ordinamento.

Abbiate cura anche nello scegliere i "borders" giusti! Personalmente ho ragionato utilizzando un cerchio che racchiudesse tutti i punti che mi occorressero, ma ci sono sia metodi più ottimizzati o metodi più veloci (ragionare a rettangoli è uno di questi).

# Dai pixel al piano cartesiano

Vi siete chiesti a cosa serva `math_point(i, j)` nello pseudo-codice?

Altro non fa che convertire la posizione del pixel in posizione del piano cartesiano. È una banale proporzione, dove avremo bisogno di:
* larghezza e lunghezza della finestra, `WIDTH` e `HEIGHT`
* gli estremi del piano cartesiano che si sta stampando, `max_x` `min_x` `max_y` e `min_y`
* il punto nello schermo che si sta calcolando.

Presi `i` ed `j`, daremo `p = {x, y}` questi valori:
```
	    max_x - min_x
p.x = i * ----------------- + min_x
		WIDTH

	    max_y - min_y
p.y = j * ----------------- + min_y
		HEIGHT
```
Spieghiamo al volo: `i` e `j` hanno come unità di misura i pixel, quindi bisogna dividerli per la lunghezza (o larghezza) della dimensione per trovare la proporzione giusta. Al chè, la moltiplichiamo per la lunghezza del piano cartesiano, in modo tale da averlo proporzionato correttamente. Infine, visto che nel 99% dei casi non si partirà a visualizzare l'area dall'origine, avremo bisogno di sommare il tutto con l'inizio della zona visualizzata.

Il motivo per cui non esplicitiamo i valori è perché questi varieranno! Specialmente nel momento in cui vorrete spostarvi o vorrete (dovrete!) zoomare all'infinito. L'unica cosa che rimarrà fissa sarà la dimensione della finestra, almeno ad inizio compilazione. Per il resto, ogni qualvolta dovrete modificare dei parametri, sia per uno zoom o per un cambio colore o per un passaggio ad un nuovo frattale, dovrete cancellare l'immagine e ricalcolarla da capo. Per quanto non sia la cosa migliore da fare, è l'unica possibilità che abbiamo in questo progetto. Abbiate quindi cura di scrivere bene il vostro codice e di renderlo funzionante in ogni caso!

***

Siamo giunti ad un buon punto della spiegazione. Non sono andato a spiegarvi tutto tutto perché ci sono varianti che potete prendere e non voglio limitare la vostra creatività e la vostra inventiva in un progetto tutto sommato limitante rispetto ad altri. Sappiate che per potervi divertire potete trovare nuove funzioni da applicare ai vostri tasti, potete creare colori particolari, calcolare il maggior numero di insiemi di frattali possibili... e una volta consegnato, potreste addirittura provare a stampare l'immagine in multi-thread o spostare fisicamente i pixel già assegnati senza andarli a ricalcolare ogni volta, velocizzando notevolmente la renderizzazione!
> A tal proposito, regalo un pacchetto di Haribo a chi mi invia il codice per il frattale del drago 🐉

Per qualunque domanda, spiegazione, chiarimento, proposta o discussione mi trovate sempre su Slack (@mcerchi) o [via mail](mailto:mcerchi@student.42roma.it). Buon lavoro!
