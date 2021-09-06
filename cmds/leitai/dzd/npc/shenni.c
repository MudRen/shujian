// /d/dzd/npc/shenni.c

#include <ansi.h>
inherit NPC;

int ask_leave();

void create()
{
	set_name(HIY"�Ϻ�����"NOR, ({
		"nanhai shenni",
		"shenni",
		"shitai",
	}));
	set("long",
		"�������ڴ��ǵ������е��Ϻ����ᣬ��Ȼ�书��ǿ��������ȥ���������졣\n"
	);

	set("gender", "Ů��");
	set("attitude", "friendly");
	set("per",30);
       set("unique", 1);
	set("class", "bonze");
	set("inquiry",([
		//"leave" : (: ask_leave :),
		//"�뿪" : (: ask_leave :),
		//"�뵺" : (: ask_leave :),
		]));

	setup();

	carry_object("/d/emei/obj/shoes")->wear();
	carry_object("/d/emei/obj/cloth")->wear();
}

int ask_leave()
{
	object me = this_player();

	message_vision(HIW"���ðɡ���$n"+HIW"�����й�һ��Ů�ᣬ������λ" + RANK_D->query_respect(me) +"��������\n"NOR,me,this_object());
	me->delete_temp("out_dzd");
	me->delete_temp("last_damage_from");
	call_out("leave_dzd",2,me);
	return 1;
}



void leave_dzd()
{
	int i,max;	
	string *oblist;
	object *obj;
	object me = this_player();
	oblist = ({"ziwei jian","zhujing bingchan","yuwang","yufeng ping","xueshen yuchanwan","haitang fen","qimenbagua tupu",
			"pi mao","tanxiang mujian","huqin","hansha sheying","wangnangu dujing","bishou","hulu","wujin beixin"});

	tell_object(me,"����Ů���ָ���£������뿪�˴��ǵ���\n");
	me->delete("maoxian_dzd");

	obj = all_inventory(me);
	max = sizeof(obj);
	for(i=0;i<max;i++) {
		if(member_array(obj[i]->query("id"),oblist) != -1)
			destruct(obj[i]);
	}
	me->move("/d/fuzhou/haigang");
	
	//link_ob->set("dzd_gift",me->query("dzd_gift"));
	//����gift ���� :)
	/*
		dzd_gift
			killed  ɱ��������Ŀ
			found    ��������
			dead  �������
			win   ������
	*/	
	
	/*
	if(!me->query_temp("dzd_winner")) {
		tell_object(me,HIY"������Լ����书��ظ������ȴ�Ѳ�����ǰ�ˡ�\n"NOR);
		me->set("combat_exp",me->query("old_exp") - 2000 );
		me->delete("old_exp");

	}
	else {
		tell_object(me,HIW"�������ǵ���ĥ�ѣ���о��Լ����书ͻ���ͽ���\n"NOR);
		exp = 8000 + random(4000);
		me->set("combat_exp",me->query("old_exp") + exp );
		me->delete("old_exp");
		pot = me->query("max_pot");
		tell_object(me,HIW"��δ��ǵ�̽�գ����ܹ������"
			+ CHINESE_D->chinese_number( exp ) 
                 + "��ʵս���飬" 
                 + CHINESE_D->chinese_number( pot )
                 + "��Ǳ�ܡ�\n"NOR);
              me->add( "potential", pot );
              if( me->query("potential") > me->query("max_pot") )
                me->set("potential", me->query("max_pot") );
	}
	*/
	me->delete("dzd_gift");
	write("�������������\n");		
}

