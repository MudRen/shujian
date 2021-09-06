#include <ansi.h>

inherit ITEM;

string *number = ({ 
"A","B","C","D","E",
"F","G","H","I","J",
"K","L","M","N","O",
"P","Q","R","S","T",
"U","V","W","X","Y",
"Z" }); 

void create()
{
        set_name("��ǩ��", ({ "box"}) );         
        set_weight(30000000);
        if( clonep() )
                set_default_object(__FILE__);
        else{
        set("unit", "��");
        set("long", "����һ��ר��������ǩ�ĺ��ӡ� ��Ҫ��ʦ�� setup ��\n");
        set("material","wood");
        set("no_get",1);
        set("value", 100000000);
        set("location", 1);
        set("size", 26); 
        }
        setup();
        set("location", 1);
}
void init()
{
    	add_action("do_get",({"��","chou"}));
    	add_action("do_set", "setup");
}

int do_set(string arg)
{
  	object me,ob;
  	string *nu;
  	int i,j;
  	i = (int)sizeof(number);
  
  	me = this_player();
  	ob = this_object();
  
  	if(!wizardp(me)) 
  		return notify_fail("����Ȩ��ô����\n");
  	if (!arg || sscanf(arg,"%d", j) != 1)
		return notify_fail ("setup <����>\n");
  	j--;
  	if( j < 1) return notify_fail("����������� 1 ��\n");
  	if( j > i) j = i;
  	ob->set("size", j);
  	ob->set("arg", number[0..j]);
  	ob->set("long","����һ��ר��������ǩ�ĺ��ӡ� ��Ҫ��ʦ�� setup ��\n");
  	nu = this_object()->query("arg");
  	message_vision("$N����ǩ����Ϊ�� A �� "+nu[j]+" ��\n",me);  
  	return 1;
}
int do_get()
{
  	object me,ob;
  	string msg, *arg;
  	int i = query("size");
  
  	me=this_player();
  
  	if(me->is_fighting() || me->is_busy()) 
  		return notify_fail("����æ���ء�\n");
  	if(!arrayp(arg = this_object()->query("arg"))) 
  		return notify_fail("���ǩ�л�û setup ��\n");
  	if(i > sizeof(arg)) i = sizeof(arg);
  	if(i <= 0) 
  		return notify_fail("ǩ�Ѿ������ˡ�\n");
  
  	msg = arg[random(sizeof(arg))];  

  	this_object()->set("arg", arg - ({ msg }));
  	ob = unew(BINGQI_D("tieling"));
  	ob->set_name(GRN+msg+" ǩ"NOR, ({ "qian"}) ); 
  	ob->set("long", "����һ֧���������ǩ������д�� "GRN+msg+NOR" ��\n");
  	ob->set("unit", "֧");
  	ob->delete("value");
  	ob->move(me);
  	message_vision("$N���ִӳ�ǩ��������һ֧$n����\n",me, ob); 
  	this_object()->set("long", this_object()->query("long")+ob->name()+" �� "+me->name()+" \n");
  	me->start_busy(2);
  	return 1;
}