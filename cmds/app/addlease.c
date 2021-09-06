/**********************************************************************************
//
//      roomleased.c
//      Created by mychat 31/04/2004
//      �����ҵ�ǩ������� free of use.
//      ��Ȼ����ӭ�޸ġ��Ż��ȡ�
//
//      Email & MSN: codemake@163.com
//      �ļ�λ��/cmds/adm��
// 		��ӵ�ǰ����Ϊ�ɳ���ķ���
***********************************************************************************/

//#include <roomlease.h>
#include <ansi.h>
#include <room.h>

int help(object me);

string id;
string *files;

int main(object me, string arg)
{
	object room; 
	string roomid;
	int valbidtype, valminirent, valminirentadd, valleasetime, 
		valminskill, valmaxskill, valdiscount;
	
	if(id&&id!="*"&&id!=getuid(me))
		return notify_fail("id����ʹ�ø�ָ�� �ȵ�Ŷ����\n");
		
	if(!arg) return help(me);
	
	if(!objectp(room = environment(me)))
		return notify_fail("��Ŀǰ�������أ�bug!!\n");
	if(arg=="add here")
	{
		id=getuid(me);
		if(!files || !sizeof(files) ) files = ({base_name(room)});
		else
		{
			if(member_array(base_name(room),files)!=-1)
				return notify_fail("�÷����Ѿ���ӣ�\n");			
			files += ({base_name(room)});
		}
		write(sprintf("�ɹ����%s,Ŀǰ�б��У�%O\n",base_name(room),files));		
		return 1;
	}
	else if(arg=="clear")
	{
		id="*";
		files=({});
		write("�б��Ѿ���ա�\n");
		return 1;		
	}
	else if(sscanf(arg, "%s %d %d %d %d %d %d %d", 
		roomid, valbidtype, valminirent, valminirentadd, valleasetime, 
		valminskill, valmaxskill, valdiscount)!=8)		
		return notify_fail("��������!!\n");	
	if(!files || !sizeof(files) ) files = ({base_name(room)});	
	if(ROOMLEASE_D->set_room(files, roomid, valbidtype, valminirent*100, valminirentadd*100, 
		room->query("short"), valleasetime*60, 
		valminskill, valmaxskill, valdiscount,base_name(room))) write(sprintf("�ɹ�����÷��䣬�����Ǹ��������б�%O\n",files));
	else write("����ʧ�ܣ�ͷ����Ŷ��\n");
	id="*";
	files=({});			
	return 1;
//	return 1;
}

int help(object me)
{
  write(@HELP
--------------------------------------------------
ָ���ʽ��addlease add here �����ⷿ�����б�
	  addlease clear ����б�
	  addlease 	roomid bidtype minirent minirentadd leasetime 
		minskill maxskill discount
		�б���⣬�Լ���գ�����ʹ�á�
--------------------------------------------------
 ����ǰ������Ϊ��Ͷ��ķ��䣬���޸ĵ�ǰ����Ͷ�����ã��޸ĵ�ǰ��������ò�
 ��Ӱ�쵱ǰ������Ͷ������������ܻᵼ�µ�ǰͶ�������б�����������仯��
 addlease ʹ�����������봦��Ҫ���õķ�����
room id Ͷ�����
bidtype		 0 ֹͣ����Ͷ��1����ʵ��Ͷ��2��������Ͷ��
minirent		���Ͷ�����(������Ϊ��λ)
minirentadd		��ͼӼ۽��(������Ϊ��λ)
leasetime		����һ�ε�ʱ�䳤��(����Ϊ��λ)
minskill		Ͷ����Ҫ������business skills ��ʱ����
maxskill		Ͷ����Ҫ�����business skills��������skill����Ͷ�꣬�������� ��ʱ����
discount		������ۿ���(���֮)
write by mychat@ln(codemake@163.com)
--------------------------------------------------

HELP
    );
    return 1;
}
