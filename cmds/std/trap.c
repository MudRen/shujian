
//trap.c ���Ϊ��


#include <ansi.h>

inherit F_CLEAN_UP;

void digging(object, int);
void create() { seteuid(getuid()); }

mapping default_dirs = ([
	"north":        "��",
	"south":        "��",
	"east":         "��",
	"west":         "��",
	"northup":      "����",
	"southup":      "�ϱ�",
	"eastup":       "����",
	"westup":       "����",
	"northdown":    "����",
	"southdown":    "�ϱ�",
	"eastdown":     "����",
	"westdown":     "����",
	"northeast":    "����",
	"northwest":    "����",
	"southeast":    "����",
	"southwest":    "����",
	"up":           "��",
	"down":         "��",
	"out":          "��",
	"enter":        "��",
]);

int main(object me, string arg)
{
	object roomfrom, roomto, roomtrap, *inv;
	mapping exits;
	string dir, *dirs;
	int i, depth;

	if( me->query("shen") >= 0)
	return notify_fail("��������ɣ����Ҵ���������а�������⣿��\n");

	if( me->query("combat_exp") >= 100000)
	return notify_fail("��������õİ�Ϸ�����������ĸ��ֲ�мΪ֮�ɣ���\n");

//	if( me->query_skill("digging", 1) <= 30)
//	return notify_fail("����㱾�¶�ûѧȫ����λ��ھ����壿\n");

	if( me->is_fighting() )
	return notify_fail("һ�ߴ��һ���ھ������ǻ����ˣ�\n");

	if( me->is_busy() )
	return notify_fail("��������æ�ţ�\n");

	if(!present("tie qiao", me))
	return notify_fail("���Ұѳ��ֵĹ��߰ɣ��\n");

	inv = all_inventory(environment(me));
	if( sizeof(inv) > 0)
	for(i=0; i<sizeof(inv); i++) {
		if( userp(inv[i]) && inv[i] != me )
		return notify_fail("������ô�����ڿ��������ڳ��������ڣ�\n");
	}

	if( !arg || !environment(me)->query("exits/" + arg) )
	return notify_fail("�����ĸ����������壿\n");

	if( strsrch(arg, "jump") >= 0 ) 
	return notify_fail("�㲻����������������壡\n");

	if( !environment(me)->query("trap_room") )
		roomfrom = environment(me);
	else	return notify_fail("�㲻��������֮���������壡\n");

	if( !roomfrom->query("outdoors"))
	return notify_fail("�㲻�������ھ����壡\n");

	if( sizeof(roomfrom->query("exits")) >= 4 )
	return notify_fail("������ͨ�������㲻�ܴ��������壡\n");

	if( roomfrom->query("cost") <= 1 )
	return notify_fail("�˴����ʼ�ʵ���ƺ������ھ����壡\n");

	if(!( roomto = find_object(roomfrom->query("exits/" + arg)) ) )
	roomto = load_object(roomfrom->query("exits/" + arg));

	if( roomto->query("trap_room") )
	return notify_fail("�Ǳ��Ѿ����˸����壡\n");

	if( !roomto->query("outdoors"))
	return notify_fail("�㲻���ڱ��˷��ſ����ڣ�\n");

	depth =  me->query_str()*2 
		+ me->query_int()*2 
		+ me->query_kar()*2
		+ me->query("jingli")/2;

	if( me->query("jingli") < depth * roomfrom->query("cost") / 10 )
	return notify_fail("������������ˣ�\n");

	roomtrap = new("/clone/misc/traproom.c");
	roomtrap->set("depth", depth/3 + random(depth*2/3));
	roomtrap->set("owner", me);
//	roomtrap->set("limit", me->query_skill("digging", 1)/10);
	roomtrap->set("roomfrom", roomfrom);
	roomtrap->set("from", arg);

	if( !undefinedp(default_dirs[arg]) )
		dir = default_dirs[arg];
	else	dir = arg;

	if(objectp(roomfrom))
		roomfrom->set("exits/" + arg, file_name(roomtrap));

	if(objectp(roomto)) {
		if( strsrch(arg, "up") >= 0 || strsrch(arg, "down") >= 0 )
			roomtrap->set("exits/" + arg, file_name(roomto));
		else
			roomtrap->set("exits/" + arg + "up", file_name(roomto));

		roomtrap->set("roomto", roomto);

		exits = roomto->query("exits");
		dirs = keys(exits);
		for(i=0; i<sizeof(dirs); i++) {
			if( exits[dirs[i]] == file_name(roomfrom) ) {
				roomto->set("exits/" + dirs[i], file_name(roomtrap));
				roomtrap->set("exits/" + dirs[i] + "up", file_name(roomfrom));
				roomtrap->set("to", dirs[i]);
				break;
			}
		}
	}

	if(objectp(roomfrom) && objectp(roomto)) {
		roomfrom->set("exits/jump" + roomtrap->query("from"), file_name(roomto));
		roomto->set("exits/jump" + roomtrap->query("to"), file_name(roomfrom));
	}

	message_vision(GRN "\n$N͵͵�����ؾ������£�����" + dir + "������һͨ������\n\n" NOR, me);
	remove_call_out("digging");
	call_out("digging", depth/100, me, depth);
	me->start_busy(depth/100);

	return 1;
}

void digging(object me, int depth)
{
	if( me->is_busy() ) {
		call_out("digging", 3, me, depth);
		if(random(5)==1) message_vision(GRN "\n$N�𾢵��������������š�����\n" NOR, me);
	}
	else {
		//me->improve_skill("digging", depth / 20);
		me->receive_damage("jingli", depth * (environment(me))->query("cost") / 10, "������������");
		tell_object(me, "���������ں���һ�����壡\n");
	}
}

int help (object me)
{
	write(@HELP
ָ���ʽ : [trap <����>]

���ָ��������ĳ�������ھ�һ�����塣

HELP
);
	return 1;
}
