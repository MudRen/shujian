// huli.c

inherit NPC;

void create()
{
        set_name("����", ({ "hu li", "li" }) );
        set("race", "Ұ��");
        set("age", 5);
        set("long", "һֻ������ɫ�ĺ��꣬���������۾������㡣\n");

        set("limbs", ({ "ͷ��", "����", "ǰצ", "��צ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 5000);

	set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 10);

        setup();
}

void init()
{
  	object me;
  	me=this_player();
  	call_out("huli", 2, me);	
}
void die()
{
       object ob;
       message_vision("$N�Һ�һ�������ˣ�\n", this_object());
       ob = new("/u/bren/test/obj/hulipi");
       ob->move(environment(this_object()));
       destruct(this_object());
}

void huli(object me)
{
    remove_call_out("huli");

               
    if (environment(me) == environment(this_object()))
    {
    message_vision("���꿴�����˹����ˣ���ಡ�������һ���굽���Աߵ��Ӳ��в����ˣ�\n",me);
    destruct(this_object());
    
    }

return 0;
}