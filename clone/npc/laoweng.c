// /u/dubei/wudang/npc/laoweng
 
inherit NPC;
int ask_me();
int ask_me1();
  

void create()
{
    set_name("��������", ({ "lao weng", "lao" }));
    set("long", "��λ���ߴ��ż��ӣ���ͷ��������ɫ����\n");
    set("gender", "����");
    set("age", 70);

    set_skill("medicine", 200);

    set_temp("apply/attack", 1000);
    set_temp("apply/defense", 1000);
    set_temp("apply/damage", 1000);

    set("combat_exp", 1000000);
    set("shen", 10000);
    set("inquiry", ([
                "��ҩ����" : (: ask_me :),
                "���" : (: ask_me1 :),
              
        ]));
    setup();

     carry_object("/clone/misc/cloth")->wear();
}

int ask_me()
{
	command("say ���䵱�Ĳ�ҩ������ż���ܿ���������ɽ��ҩ��\n");
	return 1;
}

int ask_me1()
{
        object me, ob;

        ob = this_player();
        me = this_object();
       
        command("say ����һλ�䵱��ҩ����ʧ��׹���ɽ���£������ò�ҩ·�����Լ�\n"
"ҽ�Ρ�����֮�ͣ����������£���������");
        ob->set_temp("marks/jieguo",1);
	return 1;
}