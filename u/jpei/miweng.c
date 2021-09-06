//flowray 2005.6.16
#include <ansi.h>

inherit SPEC;


void create()
{
	set_name (HIY"�鱦������"NOR, ({ "miweng","book"}));
	set("long","��������������̵�����ϰ��ʾ("HIY"show"NOR")�Ȿ���š�\n");

	set("unit","��");
	set_weight(100);
	set("value",3000000);
  //      set("no_give",1);
        set("no_drop",1);	
   //     set("no_get",1);
         set("treasure",1);
	set("degree",1);
	set("flag","spec/miweng");
	set("desc","���Ե������鱦����ȡһ���������");
        set("credit",200);
	setup();
}

void init()
{
	add_action("do_show","show");   
}

int do_show(string str)
{
	
	object my_object,me = this_player();
	
	if (!restrict()&& !me->query("buyvip")) {return notify_fail("�������Ѿ�����ʹ��"+this_object()->query("name")+"�ˡ�\n");}
	
	if (!str)
		return notify_fail("��Ҫ�Ѷ�����˭������\n");
    
	if (!(my_object = present(str, environment(me))))
		return notify_fail("��Ҫ�ҵ��˲������ȥ�����ҿ��ɡ�\n");
	
	if ( str != "zhu laoban")
		return notify_fail("������������������˿��ģ�\n");
    
	if (!living(my_object))
		return notify_fail("Ŷ������Ȱ���Ū����˵��\n");
	
	if (me->query_temp("token/maker"))
		return notify_fail("�Ȱ������ϵ�һ���ͳ�ȥ��˵�ɡ�\n");
		
	write("���ϰ���һ�������������Ǵ�ʲô�ط������ģ���\n"NOR);
	write("���ϰ�̾���������˰���,�����м���С����������ѡһ����,ǧ��Ҫ�����¸��߱��ˣ���\n");
	write("���ϰ嵽�����ó������������������ǰ��\n");
	write(HIM"��ˮ������"NOR"(necklace),"HIW"�׽����"NOR"(ring),"HIG"�������"NOR"(bangle),"+
				HIR"��������"NOR"(jade),"HIY"�ƽ���"NOR"(headgear)\n");	
	write("��Ҫѡʲô�أ�");
	input_to("choose_item", me);
	return 1;
}	 

private void choose_item(string arg, object me)
{
	object ob;
	if (arg!="necklace" && arg!="ring" && arg!="jade" && arg!="bangle" && arg!="headgear")
	{
		write("������㵽��Ҫѡʲô��");
		input_to((: choose_item :), ob,me);
		return;
	}
	
	me->set_temp("token/maker",1);
	ob=new("/clone/spec/item/box.c");
	ob->set("token/id",arg);
	

	switch(random(2)+1)
	{
		case 1:
			ob->set("token/parry",1+random(20));
			break;
		case 2:
			ob->set("token/dodge",1+random(20));			
			break;
	}

	write("��Ҫ�ڿ���ʲô���ԣ�");
	input_to("desc_item", me,ob);
	return; 
}

private void desc_item(string arg, object me,object ob)
{
	if (!strlen(strip(arg))) 
	{
		write("�㵽��Ҫ�̵�ʲô���ݰ���");
		input_to((: desc_item :),me,ob);
		return;
	}
	
	arg = explode(arg+"\n", "\n")[0];
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);
	if (strlen(strip(arg)) > 40)
	{
		write("���Ի���Ҫ���һ��,����������:");
		input_to((: desc_item :),me,ob);
		return;
	}
	arg = " "+arg+NOR+"   ��"+me->query("name")+"("+me->query("id")+") ������";
	ob->set("token/desc",arg);
	write("Ƭ�����ϰ������Ҫ�Ķ����Ͽ̺�������,����װ��һ��"HIW"ˮ������"NOR"�ｻ���㡣\n");
	ob->move(me);
	degree();
}
