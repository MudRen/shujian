// monk.c

inherit NPC;
string give_money();
object ob=this_object();
void create() 
{
set_name("�Ϻ���", ({ "old monk", "monk" }) );
	set("class", "bonze");
	set("gender", "����");
          set("age", 77);
	set("long","������һ���ɫ��ɮ�ۣ�����������ʵ�����ӡ�\n");
	set("title", "������ɨ�غ���");
	set("combat_exp", 3000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("inquiry",([
		"��Ǯ" : (:give_money:)
    	]));
	set("chat_chance", 5);
set("chat_msg", ({"�Ϻ��ж���˵������λʩ�������Ŷӡ�\n"}));
	set("max_qi", 200);
	set("max_jing", 200);
	set("neili", 200);
	set("max_neili", 200);
	set("env/wimpy", 60);

	set_skill("force", 25);
	set_skill("unarmed", 20);
	set_skill("sword", 20);
	set_skill("parry", 20);
	set_skill("dodge", 20);

  	setup();
  	carry_object("/clone/misc/cloth")->wear();
//	add_money("silver", 50);
}

void init() 
{
  	object me;
  	::init();
  	if(interactive(me=this_player()) && !is_fighting()) {
  		remove_call_out("greeting");
                call_out("greeting", 1, me);

    	}
}
void greeting(object ob)
{
   	object me;
   	me=this_player();
        if(interactive(me=this_player()) && !is_fighting()) {
   		command("look "+me->query("id"));
                command("hi "+me->query("id"));
           }
}

string give_money()
{
	object me;
	me=this_player();
  	if(!me || environment(me)!=environment()) return 0;
  	if((int)me->query("given")==1) {
    		command("kick "+me->query("id"));
    		command("faint "+me->query("id"));
    		return "����ô��ô̰�ƣ�����";
    	}
	if( (int)me->query("kar") >=20 ) {
/*
		ob->add_money("silver", 50);
		command("give "+me->query("id")+" 50 silver");
*/
		me->set("given",1);
            return "ʩ�����������ڴ������Ҳ����Ե����ϧ�������ˡ�";
    	}
	if ((int)me->query("kar")<20){	
/*
		ob->add_money("silver", 30);
		command("give "+"30 silver "+"to "+me->query("id"));
		ob->add("silver",30);
*/
		me->set("given",1);
            return "ʩ�����������ڴ������Ҳ����Ե��ҪǮû�У�����һ����";
    	}
}
