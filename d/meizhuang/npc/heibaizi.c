// NPC: /d/meizhuang/npc/huangzhonggong.c
// By action@SJ 2009/1/11

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�ڰ���", ({ "heibai zi", "zi" }));
	set("nickname", HIW"÷ׯ��ׯ��"NOR);

	set("gender", "����");
	set("age", 54);
	set("no_quest", 1);
	set("no_bark", 1);
	set("long",
      "������÷ׯ��λׯ�����еڶ��ĺڰ��ӡ�\n"
      "��һ���ɸɾ����ĺڰ����ĳ��ۡ�\n"
      "����������Ѯ����ĸߴ�˫���������, һ����֪��һλ�ڼҵĸ��֡�\n");
	set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 4000);
	set("max_jing", 4000);
	set("jingli", 4000);
	set("max_jingli", 4000);
	set("max_neili", 5000);
	set("neili", 8000);
	set("combat_exp", 2200000);
	set("attitude", "peaceful");
	set_skill("xuantian-zhi", 180);
	set_skill("art", 180);
	set_skill("medicine", 180);
	set_skill("literate", 180);
	set_skill("force", 220);
	set_skill("parry", 180);
	set_skill("tiyunzong", 180);
	set_skill("finger", 180);
	set_skill("tianmo-gong", 180);

	map_skill("force", "tianmo-gong");
	map_skill("dodge", "tiyunzong");
	map_skill("finger", "xuantian-zhi");
	map_skill("parry", "xuantian-zhi");
	prepare_skill("finger", "xuantian-zhi");

	set_temp("apply/damage", 40);
	set("chat_chance", 1);
	set("chat_msg", ({
		"�ڰ����૵�����ŻѪ�ס��������µ�һ���ף�������ܡ�����\n",
	}));

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
}      

int accept_object(object who, object ob)
{
        object me;
       // mapping fam;
        me = this_object();
/*
        if (!(fam = this_player()->query("family")) || fam["family_name"] !="�������"){
             command("thank "+ (string)who->query("id"));
             command("say ���뱾��������������֪Ϊ������˺���");
             return 0;
        }
 */      
        if (!this_player()->query_temp("meizhuangguangling")){
             command("say �㻹����ȥ���Ҵ����ӹ�ȥ���ʰɣ�");
             return 0;
        }
        
        //if (fam["generation"] == 3)
        if ((string)ob->query("id") == "ouxue pu"){
            command("haha "+(string)who->query("id"));
            call_out("destroying", 1, ob);
            command("say ����Ұ��������£��Һܸ��ˣ���ȥ���ҵ�����ͺ�������԰ɣ��������ܸ���һЩ��ʾ��");
            who->set_temp("meizhuangouxuepu",1);
            who->delete_temp("meizhuangguangling");
              return 1;
            }
        command("? "+ (string)who->query("id"));
        return 0;
}

void destroying(object obj)
{
        if(! obj) return;
        destruct(obj);
}