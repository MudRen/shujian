#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�ѱ�", ({ "fei bin", "fei", "bin" }));
        set("nickname", "��������");
        set("long", "������ʮ���꣬�е���ģ������쳣���ϴ�������Ʋ���룬����ɽ
�������������ĵ���ʦ�ܷѱ�һ�״������������кպ�������\n");
        set("gender", "����");
        set("age", 49);
        set("per", 18);
        set("attitude", "heroism");
        set("shen_type", -1);
        set("str", 25);
        set("int", 23);
        set("con", 26);
        set("dex", 26);
        
        set("max_qi", 3000);
        set("max_jing", 2000);
        set("eff_jingli", 2000);
        set("jiali", 50);
        set("combat_exp", 1500000);
        set("shen", -14000);

    set_skill("force", 150);
    set_skill("songshan-qigong", 150);
    set_skill("dodge", 150);
    set_skill("zhongyuefeng", 150);
    set_skill("strike", 160);
    set_skill("songyang-zhang", 160);
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
    set("chat_chance", 25);
    set("chat_msg", ({
                (: random_move :)
        }) );
    set("chat_chance_combat", 2);
    set("chat_msg_combat", ({
                (: perform_action, "strike.junji" :),
        }));
        setup();
        carry_object(ARMOR_D("changpao1"))->wear();
}

