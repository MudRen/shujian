// yi.c
inherit NPC;

#include <ansi.h>;
void create()
{
        set_name("����ʦ̫", ({ "dingyi shitai", "shitai", "dingyi" }) );
        set("gender", "Ů��");
        set("class", "bonze");
        set("age", 45);
        set("attitude", "peaceful");
        set("per", 24);
        set("str", 31);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 2400);
        set("max_neili", 2400);
        set("jiali", 30);
        set("max_qi",2000);
        set("max_jing",1200);
        set("combat_exp", 1200000);
        set("shen_type", 1);

        set_skill("sword", 160);
        set_skill("force", 160);
        set_skill("parry", 160);
        set_skill("dodge", 160);
        set_skill("strike", 160);
        set_skill("sixiang-zhang" ,160);
        set_skill("linji-zhuang", 160);
        set_skill("hengshan-jianfa", 160);
        set_skill("qingmang-jianfa", 160);

        map_skill("sword", "hengshan-jianfa");
        map_skill("force", "linji-zhuang");
        map_skill("strike", "sixiang-zhang");
        map_skill("parry", "hengshan-jianfa");
        map_skill("dodge", "qingmang-jianfa");
        prepare_skill("strike", "sixiang-zhang");

        create_family("��ɽ��", 13, "����");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/emei/obj/shoes")->wear();
        carry_object("/d/emei/obj/cloth")->wear();

}
