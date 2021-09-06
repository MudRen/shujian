// chuzi.c ����

inherit NPC;

int give_food();
int give_water();

void create()
{
	set_name("����", ({ "chu zi", "chuzi" }) );
	set("gender", "����" );
	set("age", 34);
	set("long",
		"����һλ�����̳�����Ĵ�ʦ��������æµ�����ղˣ����������Ҫfood��water��\n");
	set("combat_exp", 0);
	set("attitude", "peaceful");
	set("inquiry", ([
		"food" : (: give_food :),
            	"water" : (: give_water :),
	]) );
        setup();
}

int give_food()
{
	object ob=this_player();
	object me=this_object();
	object obj;

	obj=new(FOOD_D("baozi"));
	obj->move(ob);
	tell_object(ob,me->name()+"����һ�����ӡ�\n");
	return 1;
}

int give_water()
{
	object ob=this_player();
	object me=this_object();
	object obj;

	obj=new(FOOD_D("jiudai"));
	obj->move(ob);
	tell_object(ob,me->name()+"����һ���ƴ���\n");
	return 1;
}