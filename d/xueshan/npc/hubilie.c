// hubilie.c ������
// by iceland

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("������", ({ "hu bilie", "hubilie" ,"hu" }));
        set("long",@LONG
��������ɫ��𪣬��ò���ţ���ͷ��������ֹ����������üĿ֮��ȴ͸��һ
��Ӣ���������뵽ԭ����������Į���ĳɼ�˼��֮��������׵����ӡ�
LONG
        );
        set("title", HIY "�ɹ�����" NOR);
        set("gender", "����");
        set("age", 26);
        set("attitude", "friendly");
        set("shen_type", 0);
        set("combat_exp", 150000);
	set("unique", 1);

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 60);
	set_temp("apply/defense",60);
	set_temp("apply/armor", 60);
	set_temp("apply/damage", 60);


        setup();
        carry_object( MISC_D("cloth"))->wear();

        add_money("gold",1);
}

void unconcious()
{
        command("say ���ұ���");
        ::unconcious();
}

void kill_ob(object me)
{
        command("chat ץ�̿ͣ�");
        command("chat* sneer "+me->query("id"));
        me->set_temp("cike",1);
        ::kill_ob(me);
}

void init()
{
        object ob = this_player();

	::init();
	if (!ob || !visible(ob) || !present(ob, environment())) return;
        command("look " + ob->query("id"));
	command("say ��λ" + RANK_D->query_respect(ob)+"�糾���ͣ��Ǵ�������ѽ��\n");
}
