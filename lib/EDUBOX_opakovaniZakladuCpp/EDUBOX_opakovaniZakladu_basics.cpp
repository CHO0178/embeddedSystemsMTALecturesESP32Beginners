/**
 * @file EDUBOX_opakovaniZakladu_basics.cpp
 * @brief Základní příklady pro opakování základů C a C++ pro EDUBOX 1 - úvod do programování Arduina a ESP32
 */

/**
 * @brief Proměnné
 * 
 * Deklarace - vytvoření proměnné se jménem a typem, ale bez hodnoty (např. int x;)
 * Inicializace - přiřazení počáteční hodnoty proměnné pomocí operátoru = (např. int x = 5;)
 * Operátor = slouží pro přiřazení hodnoty (neplést s ==, který slouží pro porovnání)
 * 
 * @details Syntaxe: <datový_typ> <název> = <hodnota>;
 * 
 * Existují globální a lokální proměnné
 * Globální proměnné jsou dostupné v celém programu
 * Lokální proměnné jsou dostupné pouze v rámci funkce nebo bloku kódu, kde byly deklarovány
 * 
 * 
 * @note Nejdůležitější datové typy:
 * - bool (logická hodnota, 1 bajt, true nebo false)
 * - int (celé číslo, 4 bajty, -2 147 483 648 až 2 147 483 647)
 * - short (celé číslo, 1 bajt, -128 až 127)   +    byte (celé kladné číslo, 1 bajt, 0 až 255)
 * - float (reálné číslo, 4 bajty, -3.40282347E+38 až 3.40282347E+38)
 * - char (znak, 1 bajt, -128 až 127)
 * - string (řetězec znaků, dynamická velikost, závisí na obsahu)
 * 
 * @note existují také datové modifikátory, které mění velikost a rozsah proměnné, abychom mohli šetřit paměť:
 * - short (zmenší velikost int na 2 bajty, rozsah -32 768 až 32 767 - lze použít identicky jako byte - stejná velůtost 1 bajt)
 * - long (zvětší velikost int na 8 bajtů, rozsah -9 223 372 036 854 775 808 až 9 223 372 036 854 775 807)
 * - unsigned (změní interval záporných a kladných hodnot na pouze kladné hodnoty, např. unsigned int 0 až 4 294 967 295 místo -2 147 483 648 až 2 147 483 647)
 * - signed (výchozí / implicitní modifikátor, umožňuje záporné hodnoty)
 * 
 * @note NE každá proměnná musí být inicializována! ALE je dobré tak učinit, pokud je to možné (univerzálně např.: hodnotou 0),
 * protože pokud je použita pro vyhodnocení podmínky a není inicializována, bude mít náhodnou hodnotu, což povede k nedefinovaným / náhodným stavům v programu.
 * 
 * @warning Nezapomeňte, že proměnné musí být deklarovány před jejich použitím v programu!
 * 
 * @example
 * int a; // Deklarace proměnné a bez inicializace
 * int b = 5; // Deklarace a inicializace proměnné b s hodnotou 5
 * int c = a + b; // Inicializace proměnné c jako součet a a b
 * 
 * int x;
 * int d = x + y; // POZOR! - hodnota x není inicializována, takže d bude mít náhodnou hodnotu
 * 
 * @code
 * bool Motor_beh = true; // Logická proměnná - indikace běhu motoru
 * 
 * unsigned int vek = 25; // Celé číslo s použitým modifikátorem - Věk nemůže být záporný => čísla pouze v kladné hodnotě
 * float teplota = 36.5; // Reálné číslo
 * char znak = 'A'; // Znak
 * string jmeno = "EduBox"; // Řetězec znaků

 
    int hodnota = 15;    
    int volba = 2;
    int j = 0;
    int k = 0;
    int m = 0;
    int n = 0;
 * @endcode
 */



 /**
  * @brief Větvení
  * @note Větvení je blok kódu, který se provede pouze pokud je splněna podmínka
  * 
  * @note Existují různé typy větvení, které se liší způsobem, jakým se podmínka testuje:
  * - if-else (pokud-jinak) - pro jednoduché podmínky
  * - switch-case (přepínač) - pro více možností na základě hodnoty výrazu
  * 
  * @warning Nezapomeňte, že kód za podmínkou se provede, pokud je výraz pravdivý (true) 
  */


/**
 * @brief Podmíněné větvení pomocí if-else (pokud-jinak)
 * @details Syntaxe: if (podmínka) { ... } else if (podmínka) { ... } else { ... }
 * 
 * @note Pracuje na principu pokud (podmínka) pak/tak { ... } jinak { ... }
 * - aby se provedl kód za podmínkou if, výraz v závorkách musí být pravdivý (true) => jinak se provede kód za else
 * 
 * V závorkách musí být výsledek typu bool a mohou se zde tedy psát i složitější výrazy
 * Matematické Porovnávací operátory:
 * == (rovná se)
 * != (nerovná se)
 * % (zbytek po dělení / modulo) => např. i % 2 == 0 (i je sudé číslo)
 * < (menší), <= (menší nebo rovno), > (větší), >= (větší nebo rovno)
 * Logické operátory: && (A zároveň B), || (A nebo B), ! (negace výrazu)
 * 
 * @warning Neplést operátory: == (porovnání) a = (přiřazení)!
 * 
 * @example (hodnota > 10 && volba == 2) => pokud hodnota je větší než 10 A zároveň volba rovna 2
 * 
 * @code
    if (hodnota < 0) {
    // Pokud je hodnota menší než 0
    } else if (hodnota == 0) {
    // Pokud je hodnota rovna 0
    } else {
    // Pokud není menší ani rovna, musí být větší než 0
    }
 * @endcode
 */


/**
 * @brief Podmíněné větvení pomocí switch-case (Přepínač)
 * @details Syntaxe: switch (výraz) { case hodnota: ... break; ... default: ... }
 * 
 * @note switch vyhodnocuje hodnotu výrazu (většinou pouze aktuální hodnotu proměnné) a porovnává ji s jednotlivými případy case
 * case hodnoty musí být konstantní (nelze použít výrazy nebo proměnné)
 * default není nutné použít a provede se, pokud žádný case (případ) neodpovídá aktuální hodnotě výrazu
 * 
 * @warning Nezapomeňte na příkaz break; , jinak program pokračuje do dalšího case!
 * 
 * 
 * @code
 * switch (volba) {
 *   case 1:
 *    // Tento kód se provede, pokud volba == 1
 *    break;
 *  case 2:
 *   // Tento kód se provede, pokud volba == 2
 *   break;
 *  case 3:
 *   // Tento kód se provede, pokud volba == 3
 *   break;
 *  default:
 *   // Tento kód se provede, pokud volba není 1 ani 2 ani 3
 *   break;
 * }
 * @endcode
 * 
 */



/**
 * @brief Cykly
 * @note Cyklus je blok kódu, který se opakuje, dokud JE podmínka pravdivá (true)
 * 
 * @note Existují různé typy cyklů, které se liší způsobem, jakým se podmínka testuje a jak se provádí iterace:
 * - for (pro pevně daný počet iterací, např. pro procházení pole nebo seznamu)
 * - while (pokud není předem známý počet iterací)
 * - do-while (pokud chceme, aby se tělo cyklu provedlo alespoň jednou)
 * 
 * @note Existují tzv. nekonečné cykly, které nikdy neskončí, protože jejich podmínka je vždy splněna (true)
 * Např. while (true) { ... } nebo for{;;} { ... }
 * Využívá se typicky v hlavní smyčce programu (např. loop u Arduina)
 * 
 * @note Existují i vnořené cykly, které se používají pro iteraci přes více dimenzionální pole nebo seznamy
 * 
 * @warning Při chybném nastavení podmínky může dojít k zacyklení programu (např.: obrácení porovnávácího znaménka) - program se nikdy neskončí a zamrzne
 */

/**
 * @brief Cyklus while
 * @details Syntaxe: while (podmínka) { ... }
 * @param podmínka Podmínka pro pokračování cyklu (např. i < 5)
 * 
 * 
 * @note Princip: Dokud (podmínka) { ... }
 * 
 * Podmínka se testuje před každým průchodem cyklem
 * @warning Pokud je podmínka false hned na začátku, cyklus se neprovede ani jednou!
 * 
 * @code
    j = 0;
    while (j < 3) {
        // Tělo cyklu - provede se dokud j < 3
        j++;
   }
 * @endcode
 */


/**
 * @brief Cyklus for
 * @details Syntaxe: for (inicializace; podmínka; krok) { ... }
 * @param pocet_opakovani Počet opakování cyklu (např. 5) - Neboli inicializace
 * @param podminka Podmínka pro pokračování cyklu (např. i < 5)
 * @param krok Krok pro změnu hodnoty proměnné (např. i++)
 * 
 * @note Cyklus for se používá, když je znám počet opakování / kroků / iterací předem
 * (nebo je jsme schopni je spočítat např. pro procházení pole nebo seznamu)
 * 
 * Cyklus for se skládá ze tří částí:
 * 1. Inicializace – provede se jednou na začátku (např. int i = 0) - zde lze přímo uvnitř cyklu deklarovat a inicializovat proměnnou, nebo použít již existující proměnnou a podle toho přizpůsobit 3. krok - odečítání, nebo přičítání
 * 2. Podmínka – testována před každou iterací (např. i < 5) - stejné jako u podmínky if, pokud je podmínka false (podmínka už neplatí), cyklus se ukončí
 * 3. Krok – provede se po každé iteraci (např. i++, nebo i += 2, atd.) - je možné i odečítat (i--, i -= 2, atd.)
 * 
 * Např. for (int i = 0; i < 5; i++) provede tělo cyklu 5x, protože se po každém provedení těla cyklu proměnná i navýší o 1 (i = 0, 1, 2, 3, 4)
 * @note proměnnou i lze použít i v samotné logice - ideální pro procházení pole nebo seznamu
 * 
 * @warning Nezapomeňte dobře nastavit podmínku, aby cyklus neskončil příliš brzo nebo naopak nikdy neskončil - je) rozdíl mezi i < 5 a i <= 5!
 * @warning Po skončení a opuštění cyklu proměnná i zaniká a je možné ji deklarovat znovu v jiném cyklu
 * 
 * 
 * @code
    for (int i = 0; i < 5; i++) {
        // Tělo cyklu - provede se 5x (postupně pro každou hodnotu i = 0 až 4)
    }
 * @endcode
 */


/**
 * @brief Cyklus do-while
 * @details Syntaxe: do { ... } while (podmínka);
 * 
 * @note identický s cyklem while, ale tělo cyklu se vykoná alespoň jednou, protože podmínka je testována až po první iteraci
 * Vhodné např. pro vstup od uživatele, kdy se má alespoň jednou požádat o vstup
 * 
 * @warning Pokud je podmínka false, cyklus se ukončí po prvním průchodu!
 * 
 * @code
    k = 0;
    do {
        // Tělo cyklu - provede se alespoň jednou
        k++;
    } while (k < 2);
 * @endcode
 */




/**
 * @brief Ovládací příkazy break a continue
 * @note Ovládací příkazy slouží k řízení toku programu

 */

/**
 * @brief Příkaz break
 * @details Syntaxe: break;
 * 
 * @note S příkazem break jste se již setkali v předchozích kapitolách, kdy se používá v cyklech a podmínkách
 * 
 * Příkaz break okamžitě ukončí běh nejbližšího cyklu, podmínky, nebo switch a přejde na další příkaz
 * Používá se v případech, kdy je potřeba na aktuálním místě předčasně přeskočit následující příkazy, nebo ukončit cyklus
 * Např. při splnění určité podmínky nebo dosažení určitého stavu a další iterace nejsou potřeba, nebo je jejich provedení dokonce nežádoucí
 * 
 * @warning Příkaz break se používá i v příkazu switch pro ukončení aktuálního case!
 * 
 * @code
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {           // Pokud je i sudé číslo
            break;                  // Ukončí cyklus, pokud je i sudé číslo
        }
    }
 * @endcode
 */


/**
 * @brief Příkaz continue
 * @details Syntaxe: continue;
 * 
 * @note Cyklus se nepřeruší úplně, jen přeskočí daný průchod
 * 
 * Přeskočí aktuální iteraci cyklu a pokračuje další iterací => cyklus pokračuje, ale aktuální krok / iterace se přeskočí
 * Vhodné v případech, kdy chceme některé průchody cyklem vynechat (např. když hodnota nesplňuje podmínku)
 * 
 * @note Příkaz continue není tak obvyklý jako break, ale má své uplatnění
 * 
 * @example
 * for (int i = 0; i < 10; i++) {
 *   if (i % 2 != 0) {       // Pokud je i liché číslo
 *    continue;              // Přeskočí každý krok, kdy je i liché číslo
 * }
 */