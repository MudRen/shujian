inherit ITEM;

#include <ansi.h>

void create() 
  {
   set_name("ɳ��",({"shachong"}));
   set_weight(10);
   set("unit","ֻ");
   set("value",0);
   set("cook/allow",1);
   set("cook/value",1);
   set("cook/type","shachong");
   setup();
   call_out("dest", 180);
  }

void dest()
{
	object owner,me=this_object();
	string a="";
	if(owner=environment(me)){
	if(!living(owner)){
		if(owner=environment(owner))
		a="��̳�������˳�����";
	}
	else a="��������";
	if(!random(4)){
	if(owner)message("vision", me->name()+a+"�������ϣ�����ץ��ʱ���Ѿ������ˡ�\n", owner );
        destruct(this_object());
}
else call_out("dest", 180);
return;
}
return;
}
