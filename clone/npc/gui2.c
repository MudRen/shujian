// /clone/npc/guishuxin
// by dubei

inherit NPC;
 
void create()
{           
        set_name("�����", ({ "gui erniang", "gui" }));
        set("long",@LONG
�������������µĹ����������ӹ���Ƣ���ǳ����꣬������ü��
LONG
        ); 
        set("gender", "Ů��");
        set("nickname", "��ȭ�޵�");
        set("age", 58);
        set("attitude", "friendly");
        set("shen", 0);
        set("str", 35);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 6000);
        set("eff_jingli", 3500);
        set("max_jing", 2500);
        set("neili", 7000);
        set("max_neili", 7000);
        set("jiali", 150);
        set("combat_exp", 2000000); 
              set("unique", 1);
              set("per",16);
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "strike.tiangang" :)
            }));
        set_skill("strike", 200);
        set_skill("sword", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("xiantian-gong", 200);
        set_skill("tiangang-zhang",200);
        set_skill("quanzhen-jianfa", 200);
        set_skill("jinyan-gong",200);             
        set_skill("literate", 100);
        set_skill("force",200);
        map_skill("force", "xiantian-gong");
        map_skill("dodge", "jinyan-gong");
        map_skill("strike","tiangang-zhang");
        map_skill("parry", "tiangang-zhang");
        map_skill("sword", "quanzhen-jianfa");
        prepare_skill("strike", "tiangang-zhang");
 
        create_family("��ɽ��", 10, "����");
 
        setup();
        carry_object("/clone/armor/cloth")->wear();
 
}
 