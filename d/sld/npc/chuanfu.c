//wzfeng 98 10 13
//chuanfu.c
inherit NPC;
#include <ansi.h>

int ask_chuhai();
void create()
{
	set_name("����",({ "chuan fu","chuan","fu"}));
	set("long", "����һ���ϴ���ר�Ÿ�����������ȥ��ԭ�Ĵ�ֻ��\n");
	set("gender", "����");
	set("attitude", "friendly");
	set("no_get_from", 1);
	set("unique", 1);
        set("age", 55);

	set("per",15);
        set("shen", 0);
        set("str", 30);
        set("int", 25);
        set("con", 27);
        set("dex", 29);

        set("max_qi", 500); 
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 500);
        set("jingli", 200);
        set("eff_jingli", 200);
        set("jiali", 10);
        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        
	set("combat_exp", 50000);
	create_family("������",3, "����");

        set("inquiry", ([
		"chuhai" : (: ask_chuhai :),
		"����" : (: ask_chuhai :),
	]));
        
	setup();
}

void init()
{
	::init();
	if(!objectp(find_object("/d/sld/md1"))) {
		load_object("/d/sld/md1");   
	}
}

int ask_chuhai()
{
	command("say �������������ͨ�������Ҳ��ܷ��ɴ�ֻ,��Ȼ�κ��˲��������뵺������");
	return 1;
}

int accept_object(object who, object ob)
{
	if( ((string)ob->query("id") != "ling pai") || ob->query("sld") !=1 )
		return 0;

	if ( file_name(environment(this_object())) != this_object()->query("startroom")) 
		return notify_fail(CYN"�������˵���������ǵ��һص���������˵�ɡ���\n"NOR);

        this_player()->start_busy(5);
	remove_call_out("go_chuan");
		call_out("go_chuan", 2,this_player());

	call_out("destructing", 1, ob); 
	return 1;
}

void destructing(object ob)
{
	destruct(ob);
}

void go_chuan(object me)
{
	object fchuan;
	int i;
	string* fcname=({ __DIR__"obj/fc1",
__DIR__"obj/fc2",
__DIR__"obj/fc3",
__DIR__"obj/fc4",
__DIR__"obj/fc5",
__DIR__"obj/fc6",
__DIR__"obj/fc7",
__DIR__"obj/fc8",
__DIR__"obj/fc9",
__DIR__"obj/fc10",
__DIR__"obj/fc11",
__DIR__"obj/fc12",
__DIR__"obj/fc13",
__DIR__"obj/fc14",
__DIR__"obj/fc15",
__DIR__"obj/fc16",
__DIR__"obj/fc17",
__DIR__"obj/fc18",
__DIR__"obj/fc19",
__DIR__"obj/fc20" });

	for(i=0;i<sizeof(fcname);i++){
		if(!objectp(fchuan=find_object(fcname[i])))
			fchuan=load_object(fcname[i]);
		if(fchuan->query_temp("curstatus",1)!="run")
		break;
	}
	if(i>=sizeof(fcname)){
		command("say ����û�������һ��ɡ�\n");
		remove_call_out("go_chuan");
		call_out("go_chuan", 2,me); 
		return;
	}
	command("say ��Ȼ��������ͨ�����ƣ�����ʹ����ϴ���");
	if(fchuan->query_temp("curstatus",1) == "ready") {
		message_vision("\nֻ��$N���ϴ��˸����ƣ��ƺ���ʲô���š�\n",this_object());
		message_vision("��һ�����һ��С�����Ӻ��ϻ���ʻ����\n\n", this_object());
		message_vision(CYN"$N��$n˵���������Ϸ��һ��С�ģ���\n"NOR, this_object(),me);
		fchuan->set_temp("curstatus","ready2");
	}
	message_vision("$N����һԾ������С����\n",me);
        me->move(fcname[i]);
        me->start_busy(-1);
	tell_room(environment(me), me->name() + "Ծ�ϴ�����\n", ({ me }));
}
