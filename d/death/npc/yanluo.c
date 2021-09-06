#include <ansi.h>
#include <command.h>
#include <login.h>

inherit NPC;

string *death_msg = ({
        HIB "$N˵����ι�������ģ����ʲô���֣�\n\n" NOR,
        HIB "$N��������۹ⶢ��$n������Ҫ����$n��һ���Ƶġ�\n\n" NOR,
        HIB "$N���ߡ���һ�����������ͳ�һ�����ʲ�Ķ��������š�\n\n" NOR,
        HIB "$N���ϲ��ӣ�˵�����ף�����δ������ô���ܣ�\n\n" NOR,
        HIB "$N̾�������˰��ˣ����߰ɡ�\n\n"
                "һ�������Ũ��ͻȻ���֣��ܿ�ذ�Χ��$n��\n\n" NOR,
});

void create()
{
        string *first_name = ({ "�ع�","����","�ε�","����","����","ƽ��","̩ɽ","����","���","ת��" }); 

        set_name(first_name[random(sizeof(first_name))]+"��", ({ "ming wang", "ming", "wang" }) );
        set("title",  BLU"ʮ��ڤ��֮"NOR );
	set("long", "�㿴����������Ŀ��ֻ���������ϲ����κ�ϲŭ���֡�\n");
        set("attitude", "peaceful");
        set("chat_chance", 5);
        set("chat_msg", ({ 
"һ����ɭ�Ĺ������������õ��ϵ�ڤ�Ʋ�ס����˸�š�\n",
"��Ȼ��һ������Ĳҽд�Զ��������������ë���Ȼ����ס������\n",
        }) );
        set("age", 3000);
        set("combat_exp", 200000);
        set("max_jing", 1000);
        set("max_qi", 1000);
        setup();
}

#include "death.h";
