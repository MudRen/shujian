#include <ansi.h>
#include <command.h>
#include <login.h>

inherit NPC;

string *death_msg = ({
        HIW "����˵����Ŷ�������˸��µģ����ʲô���֣�\n\n" NOR,
        HIW "����˵������������������������ȥͶ̥�ɡ�\n\n" NOR,
	HIW "$n����������ͷ������ȥ����ζ���������̣������������£��������̡�\n\n" NOR,
        HIW "һ�����룬$n��������������������ǰ�����ж�Թ���ޣ��Ծ������ǡ�\n\n" NOR,
	HIW "����˵�������Ѿ�����������ȥ�ɣ���ȴ��جǰ������̥������\n\n"
                "���Ժ����У�$n�����Լ��ֶ����˹����ֻء�����\n\n" NOR,
});

void create()
{
        set_name("����", ({ "meng po", "meng", "po" }) );
        set("gender","Ů��");
        set("long","������һ����ò��ɭ���ϸ����ƹ�������ϵ�����ͤ��\n");
        set("attitude", "peaceful");
        set("chat_chance", 5);
        set("chat_msg", ({
"���źٺ�һЦ�����ɣ����ɣ��ȿ���������������ȴǰ���ɡ�\n",
"����ת���ó�һ�����룬����Ҩ��һ�����̵���������\n"
        }) );
        set("age", 2107);
        set("combat_exp", 20000);
        set("max_jing", 900);
        set("max_qi", 900);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        setup();
}

#include "death.h";

