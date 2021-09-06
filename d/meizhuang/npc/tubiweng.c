// NPC: /d/meizhuang/npc/tubiweng.c
// By action@SJ 2009/1/11

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("ͺ����", ({ "tubi weng", "weng" }));
	set("nickname", HIY"÷ׯ��ׯ��"NOR);
	set("gender", "����");
	set("age", 47);
	set("no_quest", 1);
	set("no_bark", 1);
  set("long",
       "������÷ׯ��λׯ�����е�����ͺ���̡�\n"
       "��һ���ɸɾ����İ�ɫ���ۡ�\n"
       "����������Ѯ����İ�С�����Ϲ��, һ����֪���Ǹ����׶�ŭ���ˡ�\n");
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
	set_skill("art", 180);
	set_skill("medicine", 180);
	set_skill("literate", 180);
	set_skill("force", 220);
	set_skill("parry", 180);
	set_skill("tiyunzong", 180);
	set_skill("brush", 180);
	set_skill("tianmo-gong", 180);
	set_skill("shigu-bifa", 180);

	map_skill("force", "tianmo-gong");
	map_skill("dodge", "tiyunzong");
	map_skill("brush", "shigu-bifa");
	map_skill("parry", "shigu-bifa");

	set_temp("apply/damage", 20);
	set("chat_chance", 1);
	set("chat_msg", ({
		"ͺ����̾�˿��������������ܹ��õ�����ġ������������Ҿ͡�����\n",
	}));

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
  carry_object(BINGQI_D("panguanbi"))->wield();
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
        if (!this_player()->query_temp("meizhuangouxuepu")){
             command("say �㻹����ȥ���Ҷ���ڰ���ȥ���ʰɣ�");
             return 0;
        }
        
       // if (fam["generation"] == 3)
        if ((string)ob->query("id") == "shuaiyi tie"){
            command("haha "+(string)who->query("id"));
            call_out("destroying", 1, ob);
            command("say ����Ұ��������£��Һܸ��ˣ���ȥ���ҵ��ĵܵ��������԰ɣ��������ܸ���һЩ��ʾ��");
            who->set_temp("meizhuangshuaiyitie",1);
            who->delete_temp("meizhuangouxuepu");
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