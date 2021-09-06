// lin.c
inherit NPC;

#include <ansi.h>;
void create()
{
        set_name("����", ({ "yi lin", "lin" }) );
        set("gender", "Ů��");
        set("class", "bonze");
        set("age", 16);
        set("attitude", "peaceful");
        set("per", 30);
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 1400);
        set("max_neili", 1400);
        set("jiali", 30);
        set("max_qi", 1000);
        set("max_jing", 800);
        set("combat_exp", 280000);
        set("shen_type", 1);

        set_skill("sword", 120);
        set_skill("force", 120);
        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("strike", 120);
        set_skill("sixiang-zhang" ,120);
        set_skill("linji-zhuang", 120);
        set_skill("hengshan-jianfa", 120);
        set_skill("qingmang-jianfa", 120);

        map_skill("sword", "hengshan-jianfa");
        map_skill("force", "linji-zhuang");
        map_skill("strike", "sixiang-zhang");
        map_skill("parry", "hengshan-jianfa");
        map_skill("dodge", "qingmang-jianfa");
        prepare_skill("strike", "sixiang-zhang");

        create_family("��ɽ��", 14, "����");
        set("inquiry", ([
        "�����" : "���յ�����ৡ���һ�º�������˵��������������������\n",
        ]));

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/emei/obj/shoes")->wear();
        carry_object("/d/emei/obj/cloth")->wear();
}
