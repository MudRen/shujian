//puren.c
inherit NPC;
#include <ansi.h>

void create()
{
        set_name("����", ({ "pu ren", "puren","ren" }) );
        set("gender", "����" );
        set("age", 20);
        set("long","���Ǹ����˴��������ˣ�������ת���Ĵ�������ͣ��\n");
        set("attitude", "peaceful");
        set("combat_exp",1000+random(500));
        
        set("inquiry", ([
                "����" :  "��ȥ�Ҵ�ʦ�ְɣ�\n",
                "����" :  "��ȥ�Ҵ�ʦ�ְɣ�\n",
                "�ô�" :  "�ҿɲ��������.\n",
               ]) );

        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        add_money("silver", 1);
}
