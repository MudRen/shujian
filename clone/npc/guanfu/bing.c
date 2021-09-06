// bing.c �ٱ�

inherit NPC;
#include "guanbing.h"

void create()
{
        set_name("�ٱ�", ({ "guan bing", "bing", "guanbing" }));
        set("age", 22+random(35));
        set("gender", "����");
	set("shen_type", 1);
        set("attitude", "peaceful");
        set("long", "��Ȼ�ٱ������ղ��ܺ�������ʿ��ȣ��������ǽ��������˶�������\n");

        set("age", 16 + random(40));
        set("str", 15 + random(5));
        set("dex", 15 + random(5));
        set("con", 15 + random(5));
        set("int", 15 + random(5));
	set("combat_exp", 15000+random(20000));

        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("blade", 40);
        set_skill("force", 40);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 40);

        set("chat_chance_combat", 2);
        set("chat_msg_combat", ({
                "�ٱ��ȵ����󵨵��񣬾����췴���ɣ�\n",
                "�ٱ��ȵ����ܵ��˺����ܲ������㻹�ǿ�����־��ܣ�\n",
        }));
	set("inquiry", ([
		"��͢":"��͢������Ҳ����������\n",
	]));
        setup();
        carry_object(BINGQI_D("blade"))->wield();
        carry_object(ARMOR_D("junfu"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}
