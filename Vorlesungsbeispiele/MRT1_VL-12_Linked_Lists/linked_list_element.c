/*
 * Copyright (c) 2019 Chris Iatrou <chris_paul.iatrou@tu-dresden.de>
 *
 * Hiermit wird unentgeltlich jeder Person, die eine Kopie der
 * Software und der zugehörigen Dokumentationen (die "Software")
 * erhält, die Erlaubnis erteilt, sie uneingeschränkt zu nutzen,
 * inklusive und ohne Ausnahme mit dem Recht, sie zu verwenden,
 * zu kopieren, zu verändern, zusammenzufügen, zu veröffentlichen,
 * zu verbreiten, zu unterlizenzieren und/oder zu verkaufen, und
 * Personen, denen diese Software überlassen wird, diese Rechte
 * zu verschaffen, unter den folgenden Bedingungen:
 *
 * Der obige Urheberrechtsvermerk und dieser Erlaubnisvermerk
 * sind in allen Kopien oder Teilkopien der Software beizulegen.
 *
 * DIE SOFTWARE WIRD OHNE JEDE AUSDRÜCKLICHE ODER IMPLIZIERTE
 * GARANTIE BEREITGESTELLT, EINSCHLIEẞLICH DER GARANTIE ZUR
 * BENUTZUNG FÜR DEN VORGESEHENEN ODER EINEM BESTIMMTEN ZWECK
 * SOWIE JEGLICHER RECHTSVERLETZUNG, JEDOCH NICHT DARAUF
 * BESCHRÄNKT. IN KEINEM FALL SIND DIE AUTOREN ODER
 * COPYRIGHTINHABER FÜR JEGLICHEN SCHADEN ODER SONSTIGE
 * ANSPRÜCHE HAFTBAR ZU MACHEN, OB INFOLGE DER ERFÜLLUNG EINES
 * VERTRAGES, EINES DELIKTES ODER ANDERS IM ZUSAMMENHANG MIT
 * DER SOFTWARE ODER SONSTIGER VERWENDUNG DER SOFTWARE ENTSTANDEN.
 */

#include "linked_list_element.h"

#include <stddef.h>
#include <stdlib.h>

linked_list_element* linked_list_element_new()
{
	linked_list_element* new = (linked_list_element*) malloc(sizeof(linked_list_element));
	linked_list_element_init(new);
	return new;
}

void linked_list_element_init(linked_list_element* el)
{
	if (el == NULL) return;

	el->next    = NULL;
	el->payload = NULL;

	return;
}

void linked_list_element_deleteMembers(linked_list_element* el, _Bool freePayload)
{
	if (el == NULL) return;

	if (freePayload==true && el->payload != NULL ){
		free(el->payload );
	}

	el->payload = NULL;
	el->next    = NULL;

	return;
}

void linked_list_element_delete(linked_list_element* el, _Bool freePayload)
{
	if (el == NULL) return;

	linked_list_element_deleteMembers(el, freePayload);
	free(el);
	el = NULL;

	return;
}

