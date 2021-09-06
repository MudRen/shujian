// ���� NPC
// Modify By Lane@sj 2005.01


#include <ansi.h>
inherit NPC;
#include <mudlib.h>

string ask_gold();
void create()
{
	set_name("Ǯү", ({ "qian ye","qian","ye" }) );
	set("title", "��������");
	set("nickname", HIY"Ǯ̫��"NOR);
	set("gender", "����");
	set("age",36);
	set("long","�����������ĺ�����˵�������˻ʵۣ�Ȣ��1800�����š�\n����վ����ҿ���ͨ��'ask qian ye about ����'�����һЩ�ô���");
	set("str", 30);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("per", 23);
	set("shen_type",1);
	set("combat_exp", 4500000);
	set("unique", 1);
	set("quest/�����˲�/�书/quanli",1);

	set("inquiry", ([
		"����"  : (: ask_gold :),
	]));

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
                (: exert_function, "longxiang" :),
                (: exert_function, "shield" :),
                (: perform_action, "cuff.qianjun" :),
                (: perform_action, "dazhuan" :),
	}));

	set_skill("cuff",380);
	set_skill("dodge",380);
	set_skill("force",380);
	set_skill("parry",380);
	set_skill("hammer",380);
	set_skill("strike",380);

	set_skill("huoyan-dao",380);
	set_skill("longxiang-boruo",380);
	set_skill("taizu-quan",380);
	set_skill("xiangfu-lun",380);
	set_skill("yuxue-dunxing",380);

	set_skill("huanxi-chan",200);
	set_skill("literate",200);

	set("max_qi",5974*3);
	set("max_jing",3600*3);
	set("eff_jingli",3821*3);
	set("neili",7908*6);
	set("max_neili",7908*3);
	set("jiali",200);

	map_skill("parry","taizu-quan");
	map_skill("cuff","taizu-quan");
	map_skill("force","longxiang-boruo");
	map_skill("dodge","yuxue-dunxing");
	map_skill("hammer","xiangfu-lun");
	map_skill("strike","huoyan-dao");
	prepare_skill("cuff","taizu-quan"); 
	setup();
	carry_object("/clone/weapon/hammer")->wield();
}

string ask_gold()
{
	object me, ob;
	int end_time = 1106452800; //January 23, 2005, 12:00 pm
	string site;
	
	site = lower_case(INTERMUD_MUD_NAME);

	me = this_player();
	ob = this_object();
	
	if (me->query("vip/redeem_gold"))
		return "�е��ǣ���Ϊ��������Ϊʳ����"+me->query("name")+"���"+RANK_D->query_rude(me)+"��\n����Ȼ�Ǹ�NPC�������۾���Ϲ�����Ѿ��������ˣ�������Ҫ�������Ұ�����᣿\n";
	if( me->query("combat_exp") < 100000 && me->query("birthday") < 1104508800 && !me->query("vip/redeem_gold"))
		return RANK_D->query_respect(me)+"���ҿ��㻹���������书�ɣ�";
		
	if( end_time - time() > 0 && !me->query("vip/redeem_gold") && me->query("birthday") < 1104508800 && site=="ln") //1104508800 January 1, 2005, 12:00 am
	{
		me->add("balance", 1000000);
		me->set("vip/redeem_gold",1);//���
		log_file("static/REDEEM",
				sprintf("%s ��ûƽ𲹳���\n",me->query("id")));
		return "��˵����ǰ��ʱ�����ǵ������Ҿ��ȸ���һ�����ƽ������������ϴ��������У�\n";
	}

	return "ҪǮû�У���������һ����\n";
}
