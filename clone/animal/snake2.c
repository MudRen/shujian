inherit ITEM;

#include <ansi.h>

void create()
{
   	set_name("��",({"du she", "dushe", "she"}));
   	set_weight(50);
   	set("unit","��");
   	set("value",0);
   	setup();

	if (clonep()) call_out("dest", 180);
}

void dest()
{
	object owner,me=this_object();
	string msg="";
	if(owner=environment(me)){
		if(!living(owner)){
			if(owner=environment(owner))
			msg="����������";
		}
		else msg="��������";
		if(!random(4)){
			if(owner){
				message("vision", me->name()+msg+"�ݵشڵ����ϣ�����ץ��ʱ���Ѿ������ˡ�\n", owner );
				destruct(this_object());
        		}
			else call_out("dest", 200);
		}
	}
}
