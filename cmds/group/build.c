// build.c
// by augx@sj 3/19/2002

#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me)
{
	write(@HELP
ָ���ʽ :
build [����]
����Ϊ���·���֮һ��
east,west,north,south,southeast,southwest,northeast,northwest,up,down
���������������µĵ�·��ֻ���������а��ɽ����ǵĵط������½��Լ��ĵ�·��
�����·��Ҫʯ��(shi liao)��

build room
�����������ڽ���õĵ�·�ϣ��޽����ݡ�
���췿����Ҫľ��(mu liao)��

HELP
	);
	return 1;
}

int main(object me, string arg)
{
	object material, env = environment(me);
	string env_path, dir, sdir, str, str2;
	int i,delay;
	mixed * sv;

	if( !arg ) return help(me);
	if( !env || !(env_path=(base_name(env)+".c")) || env_path[0..2]!="/d/" )
		return notify_fail("���������Ļ������޷��������ݻ��·��\n");
	if( !me->query("group/class") )
		return notify_fail("�㻹û�д����Լ��İ�ᣬ�����·���к��ã�\n");
	if( me->query("group/class") > 2 )
		return notify_fail("��ĵȼ������������޽���·�ͷ��ݡ�\n");
	if( me->is_busy() )
		return notify_fail("����æ���أ�\n");
	if( !GROUP_D->site_now(me->query("group/id")) )
		return notify_fail( GROUP_D->get_last_error() );

	if(arg!="room") {
		switch (arg) {
			case "east":		sdir = "��";	dir = "west"; 	break;
			case "north":		sdir = "��";	dir = "south";	break;
			case "west":		sdir = "��";	dir = "east";	break;
			case "south":		sdir = "��";	dir = "north";	break;
			case "southeast":	sdir = "����";	dir = "northwest";break;
			case "southwest":	sdir = "����";	dir = "northeast";break;
			case "northwest":	sdir = "����";	dir = "southeast";break;
			case "northeast":	sdir = "����";	dir = "southwest";break;
			case "up":		sdir = "��";	dir = "down";	break;
			case "down":		sdir = "��";	dir = "up";	break;
			default: return notify_fail("��Ҫ���ĸ������޽���·��\n");
		}

		if( !(material=present("shi liao",me)) || !material->query("group") )
			return notify_fail("��û��ʯ�ϣ�����޽���·��\n");
		if( stringp(env->query("exits/"+arg)) )
			return notify_fail("�Ǹ������Ѿ��г����ˡ�\n");

		if( strlen(env_path)<9
		 || env_path[0..8]!="/d/group/"
		 || (strlen(env_path)>15 && env_path[0..14]=="/d/group/entry/") ) {
			if( file_size("/d/group/"+me->query("group/id")) == -2 )
				return notify_fail("���Ѿ��ڱ�ĵط������˰��ɵ��ܶ档\n");
			if( !env->query("group") )
				return notify_fail("�㲻�������ﴴ�����ɡ�\n");
			if( mapp( env->query("exits") ) ) {
				sv = values( env->query("exits") );
				for(i=0;i<sizeof(sv);i++)
					if( strlen(sv[i])>9 && sv[i][0..8]=="/d/group/" )
						return notify_fail("�Ѿ����������ﴴ�������ˡ�\n");
			}
			if( !GROUP_D->get_entry(env_path[0..<3]) )
				return notify_fail( GROUP_D->get_last_error() );

			if( !mkdir("/d/group/"+me->query("group/id")) )
				return notify_fail("����Ŀ¼ʧ�ܣ��뱨����ʦ��\n");
			if( !mkdir("/d/group/"+me->query("group/id")+"/npc") )
				return notify_fail("����Ŀ¼ʧ�ܣ��뱨����ʦ��\n");

			GROUP_D->set_entry(me->query("group/id"),env_path[0..<3]);
			//cp(env_path,env_path[0..<3]+".origin");

			env_path = "`" + env_path;
		}
		else {
			env_path = replace_string(env_path,"/d/group/"+me->query("group/id")+"/","__DIR__`");
		}

		if( !GROUP_D->create_room(
			str = sprintf("/d/group/%s/%d.c",me->query("group/id"),time()),
			"ʯ·","����һ���ոս���ã���û�з�ˢ��ʯ·��\n",
			sprintf("`%s`:%s`,",dir,env_path),"",
			me->query("group/id"),GROUP_D->get_group_name(me->query("group/id")),
			0, env->query("have_board") )
		)
			return notify_fail("д�ļ�ʧ�ܣ��뱨����ʦ��\n");

		if( env_path[0] == '`' )
			str2 = "`" + str;
		else
			str2 = replace_string(str,"/d/group/"+me->query("group/id")+"/","__DIR__`");
		if( !GROUP_D->create_room(
			base_name(env)+".c",
			env->query("short"),env->query("long"),
			GROUP_D->get_room_exits(env)+sprintf("`%s`:%s`,",arg,str2),GROUP_D->get_room_objects(env),
			(string)env->query("group1"),env->query("outdoors")?env->query("outdoors"):env->query("indoors"),
			env->query("outdoors")?0:1, env->query("have_board") )
		)
			return notify_fail("д�ļ�ʧ�ܣ��뱨����ʦ��\n");

		message_vision("$N��ʼ��"+material->name()+"����"+sdir+"���޽���·����\n",me);
		destruct(material);
		delay = 10;
		if( wizardp(me) && me->query("env/test") ) delay = 2;
		me->start_busy(delay);

		GROUP_D->encrypt_file(str);
		GROUP_D->encrypt_file(base_name(env)+".c");
		call_out("make_finish",delay*2-1,me,0,str,base_name(env)+".c");
	}
	else {
		if( !(material=present("mu liao",me)) || !material->query("group") )
			return notify_fail("��û��ľ�ϣ���ν��췿�ݰ���\n");
		if( env->query("group1") != me->query("group/id") )
			return notify_fail("��ֻ�����Լ��İ����ｨ�췿�ݡ�\n");
		if( env->query("indoors") )
			return notify_fail("�����Ѿ����з����ˡ�\n");

		if( !GROUP_D->create_room(
			env_path,
			"����","����һ���ոս���ã���û�з�ˢ�ķ��ݡ�\n",
			GROUP_D->get_room_exits(env),GROUP_D->get_room_objects(env),
			me->query("group/id"),GROUP_D->get_group_name(me->query("group/id")),
			1, env->query("have_board") )
		)
			return notify_fail("д�ļ�ʧ�ܣ��뱨����ʦ��\n");

		message_vision("$N��ʼ��"+material->name()+"���췿�ݡ���\n",me);
		destruct(material);
		delay = 10;
		if( wizardp(me) && me->query("env/test") ) delay = 2;
		me->start_busy(delay);

		GROUP_D->encrypt_file(env_path);
		call_out("make_finish",delay*2-1,me,1,env_path,"");
	}

	return 1;
}

void make_finish(object me,int room,string file1,string file2)
{
	if( !me ) return;
	if( !room )
		tell_object(me,"��æµ�˰��죬����ѵ�·�޽����ˡ�\n");
	else
		tell_object(me,"��æµ�˰��죬���㽨����һ�����ݡ�\n");

	if( file1 && strlen(file1)>3 ) GROUP_D->update_room(file1);
	if( file2 && strlen(file2)>3 ) GROUP_D->update_room(file2);
}
