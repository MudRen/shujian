// NPC: wife.c
// Date: Look 99/04/25

inherit NPC;

string ask_me();
void create()
{
        set_name("Ů��", ({ "nv juan", "wife" }));
        set("nickname", "���Ź���");
        set("long", 
"����һ���������͵ļҾ죬�����Ư�Ʋ����������������⡣\n"
"������Լ��¶�����ε���ɫ��\n");
        set("gender", "Ů��");
        set("age", 32);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("per", 21+random(9));
        set("str", 10);
        set("int", 10);
        set("con", 10);
        set("dex", 10);
        
        set("max_qi", 200);
        set("max_jing", 200);
        set("neili", 200);
        set("max_neili", 200);
        set("eff_jingli", 200);

        set("combat_exp", 20000);
        set("score", 500);

        set_skill("force", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("strike", 20);

        set("inquiry", ([
                "Ŀ��" : (: ask_me :),
        ]));

        setup();
        carry_object("/clone/armor/green_silk")->wear();
        carry_object("/clone/armor/flower_shoe")->wear();
}

string ask_me()
{
        if (this_player()->query_temp("mubiao") == this_object()->query_temp("mubiao"))
                return "��λ"+RANK_D->query_respect(this_player())+"��ô��˽�����������ȥ��"+this_player()->query_temp("mubiao")+"�İ���";
        return "�����ز���ʶ���ҵ�Ŀ����ô������㣿";
}

void unconcious()
{
        command("corpse");
        die();
}
