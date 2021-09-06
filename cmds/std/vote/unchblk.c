// vote unchblk
#include <vote.h>
#include <ansi.h>
#include <net/dns.h>

inherit F_CONDITION;

int clear_vote(object victim);

int vote(object me, object victim)
{
	int reason; // vote for what?
	int vv;       // valid voter numbers
	int vc;       // vote count;
	int df;
	string channel, *juror, my_id, my_name, v_name;

	if (victim->query_condition("vote_chblk") > 26)
		return notify_fail("Ƶ���չرգ��������ϱ����\n");
	if ((reason = (int)victim->query("vote/reason"))>0 && (reason!=V_UNCHBLK))
		return notify_fail("Ҫ�ѵ�ǰ�ı������Ժ�ſ������µĶ��顣\n");

	if(victim->query("chblk_on"))		channel = "��̸";
	else if(victim->query("chblk_party"))	channel = "����(Party)";
	else if(victim->query("chblk_chat"))	channel = "����(Chat)";
	else if (victim->query("chblk_rumor")) 	channel = "ҥ��(Rumor)";
	else if (victim->query("chblk_sj")) 	channel = "�齣(Sj)";
	else if (victim->query("chblk_group")) 	channel = "����(Group)";
	else if (victim->query("chblk_irc")) 	channel = "������(Irc)";
	else return notify_fail(victim->name(1)+"��Ƶ���Ѿ��Ǵ򿪵��ˡ�\n");

	if (reason <= 0)
		victim->set("vote/reason", (int)V_UNCHBLK);

	my_id = me->query("id");

	// dont allow me to vote twice for the same issue
	juror = victim->query("vote/juror");

	if( !pointerp(juror) )
		victim->set("vote/juror", ({ my_id }) );
	else if( member_array(my_id, juror) == -1 )
		victim->set("vote/juror", juror+({ my_id }) );
	else{
		me->add("vote/abuse", 5);
		return notify_fail("һ��һƱ�����ñ��Ȩ��Ҫ�ܳͷ��ģ�\n");
	}

	vv = (int) ("/cmds/std/vote")->valid_voters(me)/8;
	vc = victim->add("vote/count", 1);

	df = vv - vc;
	if (vv < 4) df = 4 - vc;

	my_name = me->query("name");
	if (me == victim) v_name = "�Լ�";
	else v_name = victim->query("name");
	v_name += "("+capitalize(victim->query("id"))+")";

	if (df > 0){
		if (me == victim)
			message("vote", HIW "�������"+my_name+"ͶƱ��" +v_name +"��"+channel+"Ƶ��������"
				+chinese_number(df)+"Ʊ��\n" NOR, users());
		else
			message("vote", HIW "�������"+my_name+"ͶƱ��" +v_name +"��"+channel+"Ƶ��������"
				+chinese_number(df)+"Ʊ��\n" NOR, ({me, victim}));

		victim->apply_condition("vote_clear", 10);
	} else {
		if (me == victim)
			message("vote", HIW "�������"+my_name+"ͶƱ��"+v_name+"��"+channel+"Ƶ����"
				+my_name+"��"+channel+"Ƶ�������ˣ�\n" NOR, users());
		else
			message("vote", HIW "�������"+my_name+"ͶƱ��"+v_name+"��"+channel+"Ƶ����"
				+v_name+"��"+channel+"Ƶ�������ˣ�\n" NOR, users());

		victim->clear_condition("vote_clear");
		victim->clear_condition("vote_chblk");
		victim->delete("chblk_on");
		victim->delete("chblk_rumor");
		victim->delete("chblk_chat");
		victim->delete("chblk_party");
		victim->delete("chblk_sj");
		victim->delete("chblk_irc");
		victim->delete("chblk_group");
		victim->delete("vote/reason");
		victim->delete("vote/juror");
		victim->delete("vote/count");
	}
	return 1;
}
