// stucco.c
// by augx@sj 3/20/2002

#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me)
{
	write(@HELP
ָ���ʽ : stucco/fenshua [�������]
������ⳤ��Ϊ2��10�����֣����Լ�����ɫ�ִ���
����������һ�����32�����֣�����һ�����34�����֣�����ʹ����ɫ�ִ���
��ɫ�ִ���������34�����ֵ����ĳ����С���ɫ�ִ���ʹ�÷���ͬnick�����
��help nick��һ�䷿����������������뾡��ʹ�����ģ���ע���ʽ���롣
��ˢ������Ҫʯ��(shi hui)��

������ע�⣡���� �Ͻ���������ʹ�÷�������ɫ���֣�һ�����ֽ����ദ��

HELP
	);
	return 1;
}

int main(object me, string arg)
{
	object material, env = environment(me);
	string arg2;

	if( !arg ) return help(me);
	if( !env || !base_name(env) )
		return notify_fail("���޷���ˢ�������ڵĵط���\n");
	if( !me->query("group/class") )
		return notify_fail("�㻹û�вμӰ�ᣬ��ˢʲô��\n");
	if( env->query("group1") != me->query("group/id") )
		return notify_fail("��ֻ�ܷ�ˢ�Լ��İ���еķ��ݺ͵�·��\n");
	if( !(material=present("shi hui",me)) || !material->query("group") )
		return notify_fail("��û��ʯ�ң���η�ˢ����\n");
	if( !GROUP_D->site_now(me->query("group/id")) )
		return notify_fail( GROUP_D->get_last_error() );

	arg = GROUP_D->color_string(arg);
	arg2 = strip(arg);
	if( strlen(arg2)<4 || strlen(arg2)>20 )
		return notify_fail("������ⳤ�Ȳ����Ϲ涨��\n");

	write("�����뷿�����ϸ������\n");
	me->edit( (: call_other, this_object(), "input_long" , me, arg :) );
	return 1;
}

void input_long(object me,string arg,string str)
{
	object material, env = environment(me);
	string env_path;
	string * lines;
	int delay,i,j,k;

	env_path = base_name(env) + ".c";
	material = present("shi hui",me);

	str = GROUP_D->color_string(str);
	str = replace_string(str ,"\"", "�������ַ�");

	lines = explode(str,"\n");
	i = sizeof(lines);
	k = 0;
	if( i > 7 ) i = 7; else k = 1;
	if( i < 1 ) {
		tell_object(me,"��Ҫ�������ˢ��ʲô���ӣ�\n");
		return;
	}

	str = "";
	for(j=0;j<i;j++) {
		if( strlen( strip(lines[j]) ) > (j==0?64:68) ) {
			tell_object(me,sprintf("��%d�г��ȳ������ƣ����������롣\n",j+1));
			return;
		}
		str += lines[j];
		if( (j+1)<i || k==0 ) str += "\n";
	}

	if( !GROUP_D->create_room(
		env_path,
		arg,str,
		GROUP_D->get_room_exits(env),GROUP_D->get_room_objects(env),
		env->query("group1"),env->query("group2"),
		env->query("outdoors")?0:1, env->query("have_board") )
	) {
		tell_object(me,"д�ļ������뱨����ʦ��\n");
		return;
	}

	message_vision("$N��ʼ��"+material->name()+"��ˢ"+(env->query("outdoors")?"��·":"����")+"����\n",me);
	if(material) destruct(material);
	delay = 10;
	if( wizardp(me) && me->query("env/test") ) delay = 2;
	me->start_busy(delay);

	GROUP_D->encrypt_file(env_path);
	call_out("make_finish",delay*2-1,me,env_path);
}

void make_finish(object me,string file)
{
	if( !me ) return;
	tell_object(me,"��æµ�˰��죬�����ˢ���ˡ�\n");
	if( file && strlen(file)>3 ) GROUP_D->update_room(file);
}
