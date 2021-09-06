

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
int print_info(object usr);

int main(object me, string arg)
{
  object usr;
  object square;


  if ( !arg )
  {
	  square = find_object("/d/bwdh/sjsz/square.c");
	  if( !square || !objectp(square) )
		 square = new("/d/bwdh/sjsz/square.c");

	  return notify_fail(square->long_desc() +
			"\n\nָ���ʽ��bwscore or bwscore player\n" );
	}
	

  usr = present(arg, environment(me));
  
  
  if (!usr) usr = present(arg, me);
  if (!usr) usr = find_player(arg);
  if (usr) {
  	if( !wizardp(me) && wizardp(usr) )
        return notify_fail("û�������ҡ�\n");
	 return print_info(usr);
  }
  else 
  return notify_fail("û�������ҡ�\n");

  print_info(usr);
  destruct(usr);
  return 1;
}

int print_info(object target)
{
	string msg;
	int i;
	mapping record;
	string *players;

	if ( !objectp(target) ) return notify_fail("���޴��ˣ�\n");

	msg =  sprintf( BOLD " %s" NOR "%s\n\n", RANK_D->query_rank(target), target->short(1) );

	if( (record = target->query("bwdh")) )
	{
		msg += "������ʤ��������" + target->query("bwdh/win") + "\n";
		msg += "������ʧ�ܴ�����" + target->query("bwdh/defeated") + "\n";
		players = keys(record);
		for(i=0;i<sizeof(players);i++)
		{
			if( players[i] != "win" && players[i] != "defeated"  && players[i] != "fighting" &&
				players[i] != "once" )
	msg += "��ս����           " + players[i] + " ʤ " + target->query("bwdh/"+players[i]+"/win") + " ��  " + target->query("bwdh/"+players[i]+"/lose") + "\n";
		}

	}

	msg += "\n������             " + target->query("sjsz/team_name")+"\n";
	msg += "�ܳɼ���           " + target->query("sjsz/bw_score")+"\n";
	msg += "�ܱ��侭�飺       " + target->query("sjsz/exp")+"\n";
	msg += "�����������       " + target->query("sjsz/flag")+"\n\n";
	msg += "���γɼ���         " + target->query("sjsz/this_score")+"\n";
	msg += "���α��侭�飺     " + target->query("sjsz/this_exp")+"\n";
	msg += "�������������     " + target->query("sjsz/this_flag")+"\n\n";
	if( target->query("sjsz/red") || target->query("sjsz/white") )
		msg += "���ڱ����С�\n";

	return notify_fail(msg);
}





int help(object me)
{
write(@HELP
ָ���ʽ��bwscore or bwscore player.

���������ұ�������
HELP
	 );
	 return 1;
}

