// Npc: keshang.c ����
// Date: bobo@SJ 2000/03

inherit NPC;


void create()
{
        set_name("����", ({
                "ke shang",
                "ke",
                "shang",
        }));
        set("long",
                "����һλ��·�Ŀ��̣�׼��ȥ�Ĵ�������\n"
        );


        set("gender", "����");
        set("attitude", "peaceful");
        

        set("age", 40);
        set("shen_type", 10);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
          set("max_qi", 100);
        set("max_jing", 100);
        set("neili", 200);
        set("max_neili", 200);
        set("combat_exp", 4000);
        set("score", 100);

        set_skill("force", 10);
        set_skill("dodge", 10);
        set_skill("strike", 10);
        set_skill("parry", 10);
        set_skill("unarmed",10);


        setup();
        carry_object(__DIR__"obj/heiyi")->wear();
}

