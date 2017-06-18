use strict;
use warnings;

use Data::Dumper;

use LinkedList;
use LinkedListIterator;

my $list = LinkedList->new();

$list->push_back(2);
$list->push_front(1);
$list->push_back(3);
$list->push_back(4);
$list->push_front(6);

my $it = LinkedListIterator->new( list => $list );

while( $it->valid() ) {
	print $it->value()." ";
	$it->next();
}

print "\n";


