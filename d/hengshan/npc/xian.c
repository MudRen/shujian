// xian.c
inherit NPC;

#include <ansi.h>;
void create()
{
        set_name("����ʦ̫", ({ "dingxian shitai", "shitai", "dingxian" }) );
        set("gender", "Ů��");
        set("title", HIY"��ɽ�ɵ�ʮ��������"NOR);
        set("class", "bonze");
        set("age", 45);
        set("attitude", "peaceful");
        set("per", 31);
        set("str", 31);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 3400);
        set("max_neili", 3400);
        set("jiali", 30);
        set("max_qi",2000);
        set("max_jing",1200);
        set("combat_exp", 1700000);
        set("shen_type", 1);

        set_skill("sword", 190);
        set_skill("force", 190);
        set_skill("parry", 190);
        set_skill("dodge", 190);
        set_skill("strike", 190);
        set_skill("sixiang-zhang" ,190);
        set_skill("linji-zhuang", 190);
        set_skill("hengshan-jianfa", 190);
        set_skill("qingmang-jianfa", 190);

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

void attempt_apprentice(object ob)
{
    command("sign");
    command("say ƶ����ղ�����ͽ, �㻹��ȥ���ɿ����ɡ���\n");
    return;
}

