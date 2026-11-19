/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sech-cha <sech-cha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:50:48 by sech-cha          #+#    #+#             */
/*   Updated: 2026/11/19 14:17:05 by sech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int *ft_copy_stack_to_array(t_data *stack)
{
    t_stack *node;
    int *arr;
    int i;

    if (!stack || stack->size_stack <= 0)
        return (NULL);
    arr = malloc(sizeof(int) * stack->size_stack);
    if (!arr)
        return (NULL);
    node = stack->stack;
    i = 0;
    while (node && i < stack->size_stack)
    {
        arr[i++] = node->value;
        node = node->next;
    }
    if (i != stack->size_stack)
        return (free(arr), NULL);
    return (arr);
}

static void ft_merge(int *arr, int *tmp, int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            tmp[k++] = arr[i++];
        else
            tmp[k++] = arr[j++];
    }
    while (i <= mid)
        tmp[k++] = arr[i++];
    while (j <= right)
        tmp[k++] = arr[j++];
    i = left;
    while (i <= right)
    {
        arr[i] = tmp[i];
        i++;
    }
}

static void ft_merge_sort(int *arr, int *tmp, int left, int right)
{
    int mid;

    if (left >= right)
        return;
    mid = left + (right - left) / 2;
    ft_merge_sort(arr, tmp, left, mid);
    ft_merge_sort(arr, tmp, mid + 1, right);
    ft_merge(arr, tmp, left, mid, right);
}

static int ft_binary_search(int *arr, int len, int value)
{
    int left = 0;
    int right = len - 1;
    int mid;

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (arr[mid] < value)
            left = mid + 1;
        else if (arr[mid] > value)
            right = mid - 1;
        else
            return (mid);
    }
    return (-1);
}

int ft_index_stack(t_data *stack)
{
    t_stack *node;
    int *arr;
    int *tmp;
    int index;

    arr = ft_copy_stack_to_array(stack);
    if (!arr)
        return (0);
    tmp = malloc(sizeof(int) * stack->size_stack);
    if (!tmp)
        return (free(arr), 0);
    ft_merge_sort(arr, tmp, 0, stack->size_stack - 1);
    free(tmp);
    node = stack->stack;
    while (node)
    {
        index = ft_binary_search(arr, stack->size_stack, node->value);
        if (index < 0)
            return (free(arr), 0);
        node->index = index;
        node = node->next;
    }
    free(arr);
    return (1);
}

t_data *ft_create_empty_stack(void)
{
    t_data *stack;

    stack = malloc(sizeof(t_data));
    if (!stack)
        return (NULL);
    stack->stack = NULL;
    stack->size_stack = 0;
    return (stack);
}
