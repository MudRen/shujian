// By River 98/09
inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;
#include <ansi.h>
#include "skill.h"
#include "gfbing.h"
void create()
{
        set_name("�ٸ�ʿ��", ({ "guanfu shibing", "guanfu", "shibing" }) );
        set("gender", "����");
        set("age", 25 +random(20));
        set("long", "����һ���ٸ�����Χ�����ư��ʿ����\n");
        set("combat_exp", 10000);
        set("shen", -1500);
        set("attitude", "firendly");
        set("str", 10+random(10));
        set("int", 20);
        set("con", 20);
        set("dex", 10 +random(10));
        set("per", 20);
        set("combat_exp", 50000);
        set("shen_type", 1);
        set("no_quest", 1);
        set("attitude", "friendly");
        set("max_qi",700);
        set("max_jing",700);
        set("neili",500);
        set("max_neili",500);
        set("score", 1000);
        
        set_skill("force", 60); 
        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);

        setup();
        carry_object(ARMOR_D("junfu"))->wear();
}
