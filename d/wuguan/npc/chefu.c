//chefu.c ����

#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����", ({ "che fu","chefu","fu", "man" }));
        set("title", "����������");
        set("gender", "����");       
        set("long", "�����ƾɵĴֲ����ѣ��԰׵����������ǵ�ƣ�룬������˥�ϡ�\n");
        set("combat_exp", 5000);
        set("shen_type", 1);         
        set("age", 50);

        set_skill("force", 30);
        set_skill("strike", 30); 
	 
        set("inquiry", 
                ([
                        "����ɽ" : "�����˼���������ݵ����˰���", 
                  ]));

        setup();

        carry_object(ARMOR_D("cloth"))->wear();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}


void greeting(object ob)
{      
       command("hi "+ob->query("id"));  
       command("say ��λ" + RANK_D->query_respect(ob) +"��ϲ����ϲ�������гɣ��ܵ�������ȥ����һ���ˣ�����\n"+
               "�������ڽ����������ڶ࣬����ȥ�����أ��ȿ������ӣ�Ȼ���ٸ�������Ҫȥ��\n"+
               "���"HIR"��qu ***��"CYN"�������ȥ���������߾͵��ˡ�"NOR);       
}                               
 