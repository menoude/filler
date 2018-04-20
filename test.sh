# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    stat.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfontain <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/11 23:38:53 by tfontain          #+#    #+#              #
#    Updated: 2017/04/12 21:18:18 by tfontain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

player1=meyami.filler
player2=carli.filler

n_turns=5
map=00

# dont touch after this line --------------------------------------------------

p1=0;
p2=0;

while [ $n_turns != 0 ]
do
	./filler_vm -f ./maps/map$map -p1 \
		players/$player1 -p2 \
		players/$player2
	result=$(cat filler.trace | grep won)
	if echo "$result" | grep -q "$player1"
	then
		((p1++))
	else
		((p2++))
	fi
	((n_turns--))
done

echo $player1
echo $p1
echo $player2
echo $p2
