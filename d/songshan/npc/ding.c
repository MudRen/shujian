#include <ansi.h>
//skill level ���
inherit NPC;
inherit F_MASTER;


void create()
{
        set_name("����", ({ "ding mian", "ding", "mian" }));
        set("nickname", "������");
        set("long", "����λ���ֵ����ߣ�����Ŀ�ΰ������ɽ�������˵Ķ�ʦ�������ֶ��㡣\n");
        set("gender", "����");
        set("age", 51);
        set("per", 18);
        set("attitude", "heroism");
        set("shen_type", -1);
        set("str", 33);
        set("int", 23);
        set("con", 25);
        set("dex", 25);
        
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
        set("max_neili", 3500);
    map_skill("sword", "songshan-jian");
    prepare_skill("strike", "songyang-zhang");
    create_family("��ɽ��", 4, "����");
    
    set("inquiry", ([
                "����": "������и����ֽУ�����������(junji)����ȡ�Դ˾����塣",
                "����������": "�ٺ٣��뵱�����������˺�ɽ�������ᣬ�õľ��������Ʒ��ľ�����",
        ]));
    set("chat_chance_combat", 10);
    set("chat_msg_combat", ({
                (: perform_action, "strike.junji" :),
        }));
        setup();
        carry_object(ARMOR_D("changpao1"))->wear();        
        add_money("gold", 1);
}

void attempt_apprentice(object ob)
{
     if(ob->query_skill("songshan-qigong",1) < 90 ||
        ob->query_skill("songshan-jian",1) < 90 ||
        ob->query_skill("songyang-zhang",1) < 90){
        command("say ����书��������죬�ٻ�ȥ�����ɡ�");
        return;
        }
     command("say �ðɣ��������㻹���������ϡ�");
     command("recruit " + ob->query("id"));
}

