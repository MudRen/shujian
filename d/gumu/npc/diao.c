// By River@sj 99.5.24 

inherit NPC;
#include <ansi.h>
void create()
{
	set_name("���", ({ "shen diao", "shen", "diao"}) );
	set("long", @LONG
��ǰ��Ȼ��һͷ����ǵ��������ޣ����˻��ߣ���ò��ª֮����ȫ����ë��
�����䣬���Ǳ��˰�ȥ��һ����Ƶģ�ëɫ�ƺڣ��Ե����ǰ��࣬ģ�����һ�
���ϵ�˫��Ҳ��������ƣ���ȴ������Զ���������������ͷ������
��Ѫ��Ĵ���������������ǧ�򣬴�δ������˹�׾��������ݡ����������
������ȥ��˫����֣���ʱ�������ȴ�����̣���֪��η��裬ֻ�Ǹ���
����������һ���������š�
LONG
    );
	set("gender", "����");
	set("race", "Ұ��");
	set("age", 100);
	set("attitude", "peaceful");
	set("shen_type", 0);
	set("str", 44);
	set("int", 38);
	set("con", 42);
	set("dex", 44);

	set("max_qi", 3400);
	set("max_jing", 3000);
	set("neili", 3400);
	set("max_neili", 3400);
	set("combat_exp", 1800000);
	set("eff_jingli", 3000);

	set("limbs", ({ "����", "����", "���", "צ��" }));
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 350);
	set_temp("apply/defense", 350);
	set_temp("apply/damage", 300);
	set_temp("apply/armor", 200);

	set("dan_count", 2);
	setup();

	set("chat_chance", 3);
	set("chat_msg", ({
		"���ͻȻ����ͷ������������������΢��˻�ƣ�����Խ����������������\n",
		"���תͷ�����㣬�����ͺ����������������ͷ���ļ��¡�\n",
	}));
}

void reset()
{
        set("dan_count", 2);
}

void init()
{
	object me, ob, where, ob0;
	::init();
	ob = this_player();
	me = this_object();
	where = environment(me);
	if (interactive(ob = this_player())
	 && !is_fighting()         
	 && query("dan_count") > 0
	 && random(10) > 7
	 && file_name(where) == query("startroom")){
		remove_call_out("greeting");
		call_out("greeting", 0, ob, me, where, ob0);
	}
}

void greeting(object ob,object me,object where,object ob0)
{
	tell_object(ob,HIR"\nͻ��һ���ȳ�֮�������д���֮�඾�������ڽ���\n"NOR,);
	add("dan_count", -1);
	ob0 = new( __DIR__"dumang");
	ob0->move(where);
	message_vision(HIR"\nһ������ͻȻ���˳������������ס�\n"NOR,me);
	message_vision(HIW"\n�����ͷ�����������������������������ս��\n\n"NOR,me);
	ob->add_busy(random(2));
	me->fight_ob(ob0);
	ob0->kill_me(me);
}

void unconcious()
{
        message_vision("\n$N�����������㲽Ѹ���쳣�����߼��籼�����������ȥ��\n", this_object());
        destruct(this_object());
}

void die()
{
        message_vision("\n$N�����������㲽Ѹ���쳣�����߼��籼�����������ȥ��\n", this_object());
        destruct(this_object());
}
