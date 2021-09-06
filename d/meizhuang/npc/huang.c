// NPC: /d/meizhuang/npc/huang.c
// By action@SJ 2009/1/11

#include <ansi.h>
inherit NPC;

void create()
{
	object ob;

	set_name("���ӹ�", ({ "huangzhong gong", "huang", "gong" }));
	set("nickname", HIR"÷ׯ��ׯ��"NOR);

	set("gender", "����");
	set("age", 65);
	set("no_quest", 1);
	set("no_bark", 1);
	set("long",
      "������÷ׯ��λׯ�����е�һ�Ļ��ӹ���\n"
      "��һ���ɸɾ����Ļ�ɫ���ۡ�\n"
      "����������Ѯ������еȣ����ݺͰ����ס�\n");
	set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 4000);
	set("max_jing", 4000);
	set("jingli", 4000);
	set("max_jingli", 4000);
	set("max_neili", 5000);
	set("neili", 8000);
	set("combat_exp", 3200000);
	set("attitude", "peaceful");

	set_skill("art", 180);
	set_skill("medicine", 120);
	set_skill("literate", 160);
	set_skill("force", 220);
	set_skill("parry", 240);
	set_skill("tiyunzong", 200);
	set_skill("sword", 280);
	set_skill("tianmo-gong", 280);
	set_skill("qixian-wuxingjian", 280);
	set_skill("strike", 240);
	set_skill("tianmo-zhang", 240);

	map_skill("force", "tianmo-gong");
	map_skill("dodge", "tiyunzong");
	map_skill("sword", "qixian-wuxingjian");
	map_skill("parry", "qixian-wuxingjian");
	map_skill("strike", "tianmo-zhang");
	
	set("chat_chance", 1);
	set("chat_msg", ({
		"���ӹ�̾�˿�������˭�ܽ�������ɢ��Ū������ѽ������\n",
	}));

	set_temp("apply/damage", 260);

	setup();
        if (clonep()) {
                ob = unew(BINGQI_D("sword/yaoqin"));
                if (!ob) ob = unew(BINGQI_D("yuxiao2"));
                ob->move(this_object());
                ob->wield();
                carry_object(ARMOR_D("cloth"))->wear();
        }
}

int accept_object(object who, object ob)
{
        object me;
        //mapping fam;
        me = this_object();
/*
        if (!(fam = this_player()->query("family")) || fam["family_name"] !="�������"){
             command("thank "+ (string)who->query("id"));
             command("say ���뱾��������������֪Ϊ������˺���");
             return 0;
        }
 */       
        if (!this_player()->query_temp("mz_entrance")){
             command("say ������ô�����ģ�");
             return 0;
        }
        
       // if (fam["generation"] == 3)
        if ((string)ob->query("id") == "guangling san"){
            command("haha "+(string)who->query("id"));
            call_out("destroying", 1, ob);
            command("say ����Ұ��������£��Һܸ��ˣ���ȥ���ҵĶ��ܺڰ������԰ɣ��������ܸ���һЩ��ʾ��");
            who->set_temp("meizhuangguangling",1);
            who->delete_temp("mz_entrance");
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