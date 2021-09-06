#include <ansi.h>
#include <command.h>
#include <login.h>

inherit NPC;

string *death_msg = ({
        HIY "�ز�����������������ӷ�\n\n" NOR,
        HIY "�ز����������һֻ�֣��������޹�â������$n�Ķ���֮�ϡ�\n\n" NOR,
        HIY "�ز���������̾һ��������Ϊ���ŵ��ӣ�ȴҪ������˿��ѣ�ֻ�������ˣ����գ����գ�\n\n" NOR,
        HIY "�ز������������굱һ�������ʮ�����ѣ����ܳ��ѿຣ���ճ�������\n\n" NOR,
	HIY "�ز�������̾������Ի���Ҳ��������˭��������������߰ɣ�ȥ������ǰ������ծ��\n\n"
                HIW"$n�����Լ�����ʶԽ��Խ����������ʡ�����ˡ�����\n\n" NOR,
});

void create()
{
        set_name("�ز�������", ({ "dizangwang pusa", "pusa", "budda" }) );
        set("title",  HIY"�����ֻ���"NOR );
        set("long", "���ͷ���ף��޷��������ı���\n");
        set("attitude", "peaceful");
        set("chat_chance", 5);
        set("chat_msg", ({ 
"���������һ�󣺡������ӷ𡱵�������\n",
"���߽�������������˫�ֺ�ʮ�����ڵ��ϡ�\n",
        }) );
        set("age", 300000);
        set("combat_exp", 200000);
        set("max_jing", 1000);
        set("max_qi", 1000);
        setup();
}

#include "death.h";
