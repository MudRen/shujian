// yelvqi.c Ү����

#include <ansi.h>
inherit NPC;
void create()
{
        set_name("Ү����", ({"yelv qi", "yelv", "qi"}));
        set("gender", "����");
        set("age", 30);
        set("long", "����ؤ��ĵڶ�ʮ����������������Ů����\n");
        set("attitude", "peaceful");
        set("str", 35);
        set("int", 25);
        set("con", 35);
        set("dex", 35);

        set("max_qi", 6000);
        set("max_jing", 6000);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jiali", 100);
        set("eff_jingli",6000);
        set("combat_exp", 1800000);

        set_skill("force", 200);
        set_skill("huntian-qigong", 200);
        set_skill("strike", 200);
        set_skill("xianglong-zhang", 200);
        set_skill("dodge", 200);
        set_skill("xiaoyaoyou", 200);
        set_skill("parry", 200);

        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "xiaoyaoyou");
        prepare_skill("strike", "xianglong-zhang");

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "strike.xiao" :),
                (: exert_function, "huntian" :),
                (: perform_action, "strike.paiyun" :),
                (: perform_action, "strike.kanglong" :),
        }));
        create_family("ؤ��", 20, "����");
        setup();

	carry_object(ARMOR_D("changpao"))->wear();
	carry_object(ARMOR_D("ruanxue2"))->wear();
}