// guidao.c
// by cleansword
// 96-02-16 YZC disabled NPC killing, & "unknown" problem when revealed

#include <ansi.h>

inherit NPC;

string ask_me(object who);

void create()
{
	set_name("���ǹ���", ({ "gong zi", "gong" }) );
	set("title", "�ο�");
	set("gender", "����" );
	set("shen_type", -1);
	set("age", 25);
	set("str", 25);
	set("cor", 25);
	set("cps", 25);
	set("int", 25);
	set("long",
	"���Ǹ�ü��Ŀ������깫�ӣ��������Ƿϣ�һ�����Ѭ�ˣ�������ھ�ɫ�����Կ������ӡ�\n" );

	set("combat_exp", 20000);
	set("attitude", "heroism");
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"����˵��: �㵱����˱��ӵ��� ? ��֪������˭ ! \n",
		"���Ӻ�Ȼ����һ�����������棬��������;ȴ�ּ�æ���С�\n",
		"����˵��: ���뿪�� ! �Ҳ��ܴ���� !....\n"
	}) );

	set("inquiry", ([
		"������" : "�����ֵ�̩ɽ������˭�˲�ʶ��" ,
	        "���޼�" : "������������һ��Ҫ�����Ľ������Ƥ��",	
                "��Զ��" : "�䵱����֮�ף��������¡�",
                "������" : "�����ϳ�֮�����ڽ�����",
                "������"   : (: ask_me :),
	]) );

	set_skill("sword", 50);
	set_skill("dodge", 40);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	
	setup();
	carry_object(BINGQI_D("changjian"))->wield();
	carry_object(ARMOR_D("cloth"))->wear();
}

string ask_me(object who)
{
	int i;
	object env = environment(who);
	object *ob;

	if( !env->query("no_fight") && query("revealed") ) {
		if( is_killing(who) ) return "���Ȼ֪�����ҵ����ܣ��������������\n";
		else {
			kill_ob(who);
			who->fight_ob(this_object());
			return "֪�������ܵ��˶��������������ɣ�\n";
		}
	}

	if( (env->query("no_fight") || random(10) < 5) || is_fighting() )
		return "���......\n";

	set_temp("apply/attack",  50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage",  20);

	message("vision",
		HIY "���ǹ�������ͻȻ�ų����ԵĹ�â��ŭ��˵�����㾹�����ܹ�������֣���\n"
		"���ǹ��Ӵ��һ�����е������³���������֮�⣬�����ܹ�����˶���������\n" 
		"������ʹ���������������棬���ͺ�����̫���񽣶˵ķ�ͬС�ɡ�\n" NOR,
		environment(), this_object() );
	set("title","�����ϳ�");
	set_name("������",({ "song qingshu", "song", "qingshu" }));
	set("pursuer", 1);
	set("vendetta/authority", 1);
	set("chat_chance", 15);
	set("chat_msg", ({
		(: random_move :)
	}));
	set("bellicosity", 10000);
	set("combat_exp", 300000);
	set("max_qi",1400);
	set("qi", 1400);
	set("eff_qi", 1400);
	set("max_neili",1200);
	set("neili", 1200);
	set("eff_jingli",1000);  
	set("jingli", 1000);
	set("max_jing", 1000);
	set("eff_jing", 1000);
	set("jing", 1000);

	set_skill("force", 100);
	set_skill("yinyun-ziqi", 100);
	set_skill("dodge", 100);
	set_skill("tiyunzong", 100);
	set_skill("cuff", 100);
	set_skill("taiji-quan", 100);
	set_skill("parry", 100);
	set_skill("sword", 120);
	set_skill("taiji-jian", 120);
	set_skill("taoism", 30);
	set_skill("literate", 40);

        map_skill("force", "yinyun-ziqi");
	map_skill("dodge", "tiyunzong");
	map_skill("cuff", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	prepare_skill("cuff", "taiji-quan");
        ob = all_inventory(environment());
	for(i=sizeof(ob)-1; i>=0; i--) {
		if( !userp(ob[i]) ) continue;
                if((int)ob[i]->query("combat_exp",1)<50000) continue;
		kill_ob(ob[i]);
		ob[i]->fight(this_object());
	}
        add_money("gold", 2);
	set("revealed", 1);
	return "���³���������֮�⣬�����ܹ�����˶�������\n";
}
