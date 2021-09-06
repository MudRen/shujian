#include <ansi.h>
inherit NPC;

void create()
{
        set_name("��Ӣ��", ({ "tang yinge", "tang", "yinge" }));
        set("nickname", "����̫��");
        set("long", "����һ�����������ߣ�������������ʦ�ܡ�\n");
        set("gender", "����");
        set("age", 45);
        set("per", 20);
        set("attitude", "heroism");
        set("shen_type", -1);
        set("str", 26);
        set("int", 26);
        set("con", 26);
        set("dex", 27);
        
        set("max_qi", 3000);
        set("max_jing", 2000);
        set("eff_jingli", 2000);
        set("jiali", 50);
        set("combat_exp", 1500000);
        set("shen", -15000);

    set_skill("force", 150);
    set_skill("songshan-qigong", 150);
    set_skill("dodge", 160);
    set_skill("zhongyuefeng", 160);
    set_skill("strike", 150);
    set_skill("songyang-zhang", 150);
    set_skill("parry", 150);
    set_skill("sword", 150);
    set_skill("songshan-jian", 150);
    set_skill("literate", 100);
    map_skill("force", "songshan-qigong");
    map_skill("dodge", "zhongyuefeng");
    map_skill("strike", "songyang-zhang");
    map_skill("parry", "songshan-jian");
    map_skill("sword", "songshan-jian");
    prepare_skill("strike", "songyang-zhang");
    create_family("��ɽ��", 4, "����");
    set("chat_chance_combat", 10);
    set("chat_msg_combat", ({
                (: perform_action, "sword.feiwu" :),
                (: perform_action, "sword.jianqi" :),
        }));
        setup();
        carry_object(ARMOR_D("changpao1"))->wear();
        carry_object(BINGQI_D("changjian"))->wield();   
        add_money("gold", 1);
}

