#include <ansi.h>
inherit ROOM;

string *ids = ({  }); 
int get_setup(object me);
void checking(object me);
void create()
{
        set("short", "����������");
        set("long", "������"+MUD_NAME+"����������ҡ�
Ҫ���������˽����Ȩ�ޣ���ʹ�� setup ���ɾ������ move ���\n");
        set("exits", ([
               "out" : "/d/wizard/wizard_room"
        ]));
        set("no_death", 1);
        set("no_save", 1);
	set("no_fight", 1);
        setup();
}

void init()
{
       string wiz_status;
       object me;

       me = this_player();
       wiz_status = SECURITY_D->get_status(me);
       
       if( wiz_status != "(admin)" && !get_setup(me)){
       	              message_vision("\n$N͵͵���˹�������Ȼһ��������$P���͵���ʱ�յ���һ����\n\n",me);
                      me->move("/d/city/chmiao");
                      }
       else checking(me);
       if( wiz_status == "(admin)"){
       	     add_action("do_setup", "setup");
       	     add_action("move_setup", "move");
       	     }
}

void checking(object me)
{
	object snooper;
	string wiz_status = SECURITY_D->get_status(me);
	
	if (!me || environment(me) != this_object()) return;
	else if (wiz_status != "(admin)" && !get_setup(me)){
       	              message_vision("\n��Ȼһ��������$N���͵���ʱ�յ���һ����\n\n",me);
                      me->move("/d/city/chmiao");
                      }
        else if (objectp(snooper = query_snoop(me))){
                  message_vision(HIW"\n$NͻȻ�����һ�����ұ�"+snooper->short(1)+"�����ˣ�Ȼ��ͽ���˼�������\n\n"NOR, me);
                snoop(snooper);
                      }
    call_out("checking", 1, me);
}

int move_setup(string arg)
{
	object me,ob;
	int i;
	me = this_player();
	if (previous_object() && getuid(previous_object()) != ROOT_UID) return 0;
	if (!arg) return notify_fail ("�ٺ٣���׼��ɾ��˭���������Ȩ�ޣ�\n");
        if (!objectp(ob = LOGIN_D->find_body(arg)))
                  return notify_fail("��׼��ɾ��˭���������Ȩ�ޣ�\n");
        if (ob == me)
                  return notify_fail("�����ڿ���Ц�ɣ�\n");
        for(i=0;i<sizeof(ids);i++)
                 if(ids[i]==ob->query("id"))
                 	 ids = ids - ({ ob->query("id") });      	 

        write("��ɾ����"+ob->name()+"���������Ȩ�ޡ�\n");
       
	return 1;
}

int do_setup(string arg)
{
	object me,ob;
	int i;
	me = this_player();
	if (previous_object() && getuid(previous_object()) != ROOT_UID) return 0;
	if (!arg) return notify_fail ("�ٺ٣���׼����˭���������Ȩ�ޣ�\n");
        if (!objectp(ob = LOGIN_D->find_body(arg)))
                  return notify_fail("��׼����˭���������Ȩ�ޣ�\n");
        if (ob == me)
                  return notify_fail("�����ڿ���Ц�ɣ�\n");
        for(i=0;i<sizeof(ids);i++)
                 if(ids[i]==ob->query("id"))
                 	 return notify_fail("�����Ѿ����˽��������Ȩ�ޡ�\n");       	 
        
        ids = ids + ({ ob->query("id") });
        write("�������"+ob->name()+"���������Ȩ�ޡ�\n");
       
	return 1;
}

int get_setup(object me)
{
        int i;
        for(i=0;i<sizeof(ids);i++)
                 if(ids[i]==me->query("id"))
                 	 return 1;       	 
        
        return 0;
}
