// Npc: /kungfu/class/shaolin/cheng-ji.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;
int ask_wuse();
string ask_luohan();

void create()
{
	set_name("�μ�", ({
		"chengji luohan",
		"chengji",
		"zhihui",
		"luohan",
	}));
	set("long",
		"����һλ�뷢���׵���ɮ����һϮ��ߺڲ����ġ�������ݸߣ�\n"
		"̫��Ѩ�߸߹����ƺ��������书��\n"
	);

	set("nickname", "�ǻ��޺�");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 60);
	set("shen", 5000);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 500000);
    set("unique", 1);

	set_skill("force", 100);
	set_skill("yijin-jing", 100);
	set_skill("dodge", 100);
	set_skill("shaolin-shenfa", 100);
	set_skill("club", 100);
	set_skill("weituo-gun", 100);
	set_skill("parry", 100);
	set_skill("buddhism", 100);
        set_skill("yizhi-chan", 100);
        set_skill("finger", 100);
	set_skill("literate", 100);

	map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("club", "weituo-gun");
	map_skill("parry", "weituo-gun");
        map_skill("finger", "yizhi-chan");
        set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: perform_action, "finger.wofu" :)
	}));    
        prepare_skill("finger", "yizhi-chan");    

	create_family("������", 37, "����");
        set("inquiry", ([
                 "��ɫ��ʦ" : (: ask_wuse :),
                 "���޺�" : (:ask_luohan:),
	]));
        set("luohan_count",1);
        setup();

        carry_object("/d/shaolin/obj/qimeigun")->wield();
        carry_object("/d/shaolin/obj/cheng-cloth")->wear();
}


#include "/kungfu/class/shaolin/cheng.h"

 int ask_wuse()
{
  say("�μŴ�ʦ˵������ɫ��ʦ��������ǰ����ɮ��ƾ��һ�������书\n"
      "���������������֮�£��������Ĺ�ɵ�����������������ʦ��Ů\n"
      "�����Ǻ��ѡ���ִ���޺�����ʮ����ܽ��ұ��ɾ����������ɹ���֮\n"
      "��ɼ�����һ���޺�ȭ֮�У����������޺����еĵ�һ��ɮ��������\n"             
      );
  this_player()->set_temp("marks/�޺�",1); 
  return 1;
 }
 string ask_luohan()
{
 object ob;
 mapping fam;

	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";
 if ((int)this_player()->query_temp("marks/�޺�")) {
       if (query("luohan_count") < 1)   
           return "��ʦ����ȥ��ϰ�ˣ��Ҿ���ȴ�ˣ�";
       say("������޺������������似����Ҫ����������ɫ��ʦ�����Ƴɴ˱�\n"
           "��������Ů���������־��䵱�����˹黹���ɡ��������޺�������\n"
           "֮����\n");
       ob=new("/d/shaolin/npc/obj/book-iron");
       ob->move(this_player());
       add("luohan_count", -1);
       message_vision("�μŴӻ����ͳ�һ�����޺��ݸ�$N��\n",this_player());
       this_player()->delete_temp("marks/�޺�");
       return "��Ҫ������ϰ�����ɴ�ʧ����ѧϰ�����Ļ�Ե��";
      }
     else
        return "���޺�������ѽ��������ֻ�н�ͭ��ľ���ּ������������";
    }
