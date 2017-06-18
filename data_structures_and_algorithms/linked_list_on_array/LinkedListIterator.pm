package LinkedListIterator;

use Moose;

use LinkedList;

has list => (
		is => 'ro',
		isa => 'LinkedList'
	);

has _current => (
		is => 'ro',
		isa => 'Int',
		default => sub {
			my $self = shift;

			return $self->{list}->{head};
		}
	);

sub next {
	my $self = shift;

	$self->{_current} = $self->{list}->{next}->[ $self->{_current} ];
}

sub valid {
	my $self = shift;

	return $self->{_current} != -1;
}

sub begin {
	my $self = shift;

	$self->{_current} = $self->{list}->{head}; 
}

sub value {
	my $self = shift;

	return $self->{list}->{data}->[ $self->{_current} ];
}

sub pos {
	my $self = shift;

	return $self->{_current};
}

1;