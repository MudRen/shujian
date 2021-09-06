// open.c
// modify by augx@sj 3/27/2002

#include <room.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mapping doors;
	string *dirs, dir, str;
	object room, door;
	int i,delay;

	if( !arg ) return notify_fail("��Ҫ��ʲô��\n");

	if( sscanf(arg,"%s at %s",arg,dir) == 2 ) {
		if( !environment(me)->query("group1") )
			return notify_fail("��ֻ�����Լ��İ����￪���Լ��Ĵ��š�\n");
		if( !(str=environment(me)->query("exits/"+dir)) )
			return notify_fail("û���������\n");
		if( !(room=find_object(str)) )
			if( !(room=load_object(str)) )
				return notify_fail("������������⣬�뱨����ʦ��\n");
		if( !room->query("group1") || room->query("group1")!=me->query("group/id") )
			return notify_fail("��ֻ�������ַ�ʽ�����Լ����ɵĴ��š�\n");
		if( !(door=present(arg,room)) )
			return notify_fail("�Ǹ��ط�û���Ű���\n");
		if( door->query("open") )
			return notify_fail("���Ѿ����ˡ�\n");

		message_vision("$Nʹ������ȥ�ƶ�"+door->name()+"������"+door->name()+"......\n",me);
		tell_room(room,me->name()+"ʹ������ȥ�ƶ�"+door->name()+"������"+door->name()+"......\n");
		door->set("open",1);
		door->do_name();

		delay = 5;
		if( wizardp(me) && me->query("env/test") ) delay = 2;
		me->start_busy(delay);
		return 1;
	}

	doors = environment(me)->query_doors();
	if( mapp(doors) ) {
		dirs = keys(doors);
		if( member_array(arg, dirs)!=-1 ) dir = arg;
		else for(i=0; i<sizeof(dirs); i++)
			if( arg==doors[dirs[i]]["name"] || member_array(arg, doors[dirs[i]]["id"])!=-1 ) {
				dir = dirs[i];
				break;
			}
		if( !dir ) return notify_fail("��Ҫ��ʲô��\n");

		if( environment(me)->open_door(dir) ) {
			message_vision("$N��" + doors[dir]["name"] + "�򿪡�\n", me);
			return 1;
		}
	}

	return 0;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : open <door>
           open <door> at <����>

���ָ������������.

HELP
    );
    return 1;
}
