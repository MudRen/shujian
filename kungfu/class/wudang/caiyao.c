// caiyao.c ��ҩ����
#include <ansi.h>;
inherit NPC;

string ask_me();
int ask_me1();
int ask_me2();
int ask_me3();
int ask_me4();
int accept_object(object who, object ob);
void destroying(object me, object obj);

void create()
{
	set_name("��ҩ����", ({ "caiyao daozhang", "caiyao", "daozhang" }));
	set("long", "�����䵱ɽ�Ĳ�ҩ������\n");
	set("gender", "����");
	set("age", 60);
	set("attitude", "peaceful");
	set("shen", 1000);

	set("str", 20);
	set("int", 20);
	set("con", 25);
	set("dex", 20);

	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 500);
	set("max_neili", 500);

	set("combat_exp", 50050);
	set("score", 5000);

	set_skill("force", 60);
	set_skill("dodge", 40);
	set_skill("cuff", 60);
	set_skill("taiji-quan", 60);
	set_skill("unarmed", 40);
	set_skill("parry", 40);
	set_skill("sword", 40);
	set_skill("taiji-jian", 40);
	set_skill("taoism", 40);

	map_skill("cuff", "taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");
	prepare_skill("cuff", "taiji-quan");
	create_family("�䵱��", 4, "����");

	set("inquiry", ([
		"�ŵ�" : (: ask_me :),
		"ҩ��" : (: ask_me1 :),
		"ֻ��" : (: ask_me2 :),
		"���" : (: ask_me3 :),
		"ҩ��" : (: ask_me4 :),
	]));

	set("book5_count", 1);
	set("book6_count", 1);

	set("chat_chance", 3);
	set("chat_msg", ({
		CYN"��ҩ�����п������벻������ɽ�ﻹ��һ��������εĹŵ���\n"NOR,
		CYN"��ҩ����������Թ�������Ǵ�ͷϺ����Ȼ��ҩ����Ū���ˣ���!���û�ȥ����һ�ѡ�\n"NOR,
	}));

	setup();
	carry_object("/d/wudang/obj/greyrobe")->wear();
	carry_object("/d/wudang/obj/daolv")->wear();
}

void reset()
{
	set("book5_count", 1);
	set("book6_count", 1);
}

int accept_object(object who, object ob)
{
         object me;
         object obzi;
         me = this_player();
         if( !who || environment(who) != environment() ) {return 0;}
         if ( !objectp(ob) ) return 0; 

         if ( !present(ob, who) ) return notify_fail("��û�����������");

         if ((string)ob->query("id") == "yao chu"){
                if ( file_name(environment(this_object())) != this_object()->query("startroom")){
                     command("say �����ڲ����䵱ɽ·�������ҩ��Ҳû���á�");
                     return 0;
                }
                command("say ����������Ҫ�ģ�Ϊ�˱������Ҿʹ��㵽һ����ĵط�ȥ��!");
                remove_call_out("destroying");
                call_out("destroying", 1, this_object(), ob);
                command("say �����������Ҳ�ҩ�õģ���Ҳһ������ȥ�ɣ�˵��������!");
                obzi=new("/d/wudang/obj/shengzi");
                obzi->move(me);
                me->move("/d/wudang/houshan/gudao1");
                return 1;
        }
        return 0;
}

string ask_me()
{
        return "Ϊ�˷�����ŵ���������ͷ�����ˣ��ɲ������׸�����!\n";
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}

int ask_me1()
{
        command("say ��׳��֮ʱ�������䵱��ɽ��ҩ��������׹���£�����һλ\n"
                "�������ȣ����˴����֮�󣬾�������ȥ���������ĺ�꣬��������ֻ��...");
        return 1;
}

int ask_me2()
{
        object book5, me, ob;

        me = this_object();
        ob = this_player();

	if(ob->query_temp("marks/ask2")){
		command("say " + RANK_D->query_respect(ob) + "�Ƿ��̽���˽����\n");
		return 1;
        }
	if (query("book5_count") < 1){
		command("say �Ѿ������ڰ��Ҵ�̽����ͷ��˵�ɡ�\n");
		return 1;
        }
	if (query("book5_count") >0){
		command("say ���" + RANK_D->query_respect(ob) + "�ܰ���Ѱ�ҵ���λ���˵��������ұؽ��м�\n"
			"������������һ������ۣ��䲻��ʲ��ϡ�б����ƽ����Ҳ�����ҵ�����" + RANK_D->query_respect(ob) + "���£�\n"
			"�Ա��ҵ����⡣");
		book5 = new(MEDICINE_D("m-book5"));
		book5->move(ob);
		add("book5_count", -1);
		message_vision("$N����$nһ������ۡ�\n", me, ob);
		ob->set_temp("marks/ask2",1);
		return 1;
	}
}

int ask_me3()
{       
        object book6, me, ob;

        me = this_object();
        ob = this_player();

	if(!ob->query_temp("marks/jieguo")){
		command("say " + RANK_D->query_respect(ob) + "��û��̽������̸��������������Զ������أ�\n");
		command("disapp " + ob->query("id"));
		return 1;
        }   
        if (query("book6_count") < 1){
		command("say �������ˣ��Ѿ������ڰ��Ҵ�̽���˽����\n");
		return 1;
        } 
        if (query("book6_count") >0){
		command("thank " + ob->query("id"));
		command("say ��λ" + RANK_D->query_respect(ob) + "�Զ����ţ������ҵ����ն��ˣ��ϵ����Իر�����������һ��\n"
			"�����ֳ����������������Ĳ���ϡ�����������йر���ҩ��ľ��⡣" + RANK_D->query_respect(ob) + "������£�Ҳ��\n"
			"�������һЩ�á�");
		book6 = new(MEDICINE_D("m-book6"));
		book6->move(ob);
		add("book6_count", -1);
		message_vision("$N����$nһ������ϡ������\n", me, ob);
		ob->delete_temp("marks/jieguo");
		ob->delete_temp("marks/ask2");
		return 1;
	}
}

int ask_me4()
{    
	int roomn,yaon;
	object me, who;
	me = this_object();
	who = this_player();
        
	roomn = who->query_temp("caiyao_room",1);
	yaon = who->query_temp("caiyao_name",1);

	if(!who->query_temp("caiyao_room")) {
		command("say �䵱ɽɽ��ҩ���ڶ࣬����������ȥѰѰ��\n");
		return 1;
	}   
	if (roomn < 5){
		command("say ����˵��" +yaon+ "����ǰЩʱ���������һ���ֲɼ���һЩ��\n");
		return 1;
	} 
	if (4 < roomn && roomn < 9){
		command("say ����˵��" +yaon+ "����ǰЩʱ����������Ҷ���ֲɼ���һЩ��\n");
		return 1;
	} 
	if (8 < roomn && roomn < 13){
		command("say ����˵��" +yaon+ "����ǰЩʱ�������ڻ�ѩ���ֲɼ���һЩ��\n");
		return 1;
	}
	if (12 < roomn){
		command("say ����˵��" +yaon+ "����ǰЩʱ����������Ҷ���ֲɼ���һЩ��\n");
		return 1;
	}  
	return 1;
}
