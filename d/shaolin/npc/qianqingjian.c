// qianqingjian.Ǯ�ཡ
inherit NPC;
 
void create()
{
        set_name("Ǯ�ཡ", ({ "qian qingjian", "qian", "qingjian" }));
        set("nickname", "ɥ�Ÿ�");
        set("long", 
        "�����ǻƺ��Ĺ��Ǯ�ཡ��\n"
        " һ���ƻ���˵����ӡ�\n");
        set("gender", "����");
        set("age", 32);
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 22);
        set("con", 23);
        set("dex", 22);
        
        set("max_qi", 700);
        set("max_jing", 600);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 20);
        set("combat_exp", 290000);
        set("shen", -2900);

    set_skill("force", 90);
    set_skill("xuantian-wuji", 100);
    set_skill("dodge", 90);

    set_skill("taxue-wuhen", 100);
    set_skill("strike", 90);
    set_skill("parry", 90);
    set_skill("kunlun-zhang", 80);
    set_skill("literate", 60);
    map_skill("force", "xuantian-wuji");
    map_skill("dodge", "taxue-wuhen");
    map_skill("strike", "kunlun-zhang");
    map_skill("parry", "kunlun-zhang");
    prepare_skill("strike", "kunlun-zhang");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
//        add_money("gold", 5);
}